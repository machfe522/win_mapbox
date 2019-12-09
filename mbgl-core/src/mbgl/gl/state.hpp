#pragma once

//#include <tuple>

namespace mbgl {
namespace gl {



	template<class... _Types>
	class Tuple;

	//============================================
	//Tuple类通过Get<int>(Tuple)函数获取元组数据的实现。

	template<size_t _Index, class _Tuple>
	struct Tuple_element;

	template<size_t _Index>
	struct Tuple_element<_Index, Tuple<>>
	{
		static_assert(((int)_Index) < 0, "Tuple index out of bounds");
	};

	template<class _This, class... _Rest>
	struct Tuple_element<0, Tuple<_This, _Rest...>>
	{
		using type = _This;
		using _Ttype = Tuple<_This, _Rest...>;
	};

	template<size_t _Index, class _This, class... _Rest>
	struct Tuple_element<_Index, Tuple<_This, _Rest...>>
		: public Tuple_element<_Index - 1, Tuple<_Rest...>>
	{
	};

	//-----------------------------------------------------

	template<size_t _Index, class _Tuple>
	using Tuple_element_t = typename Tuple_element<_Index, _Tuple>::type;

	template<size_t _Index, class... _Types>
	constexpr Tuple_element_t<_Index, Tuple<_Types...>>& Get(Tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename Tuple_element<_Index, Tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst);
	}

	template<size_t _Index, class... _Types>
	constexpr Tuple_element_t<_Index, Tuple<_Types...>>& Get(const Tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename Tuple_element<_Index, Tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst);
	}

	//=================================================================
	//Tuple类相关的Forward_as_Tuple函数实现。

	template<class... _Types>
	constexpr Tuple<_Types&&...> Forward_as_Tuple(_Types&&... _Args) noexcept
	{
		return (Tuple<_Types&&...>(static_cast<_Types&&>(_Args)...));
	}

	//=================================================

	template<class _Ty>
	constexpr _Ty&& Forward(_Ty& _Arg) noexcept
	{	 
		return (static_cast<_Ty&&>(_Arg));
	}

 
	template<>
	class Tuple<>
	{
	public:
		constexpr Tuple() noexcept
		{
		}

		//------------------------------

		Tuple(const Tuple<>&) = default;
		//Tuple(Tuple<>&) = default;

		constexpr Tuple(Tuple<>&& _Right)
		{

		}
		

	};

	template<class _This>
	class Tuple<_This>
		: private Tuple<>
	{
	public:
		typedef Tuple<> _Mybase;

	public:
		constexpr Tuple() noexcept
			:_Mybase()
		{
		}

		constexpr Tuple(_This&& _This_arg) noexcept
			:_Mybase(), _Myfirst(static_cast<_This&&>(_This_arg))
		{
		}

		//-------------------------------------------------
		Tuple(const Tuple<_This>&) = default;
		//Tuple(Tuple<_This>&) = default;

		constexpr Tuple(Tuple<_This&&>&& _Right)
			: _Myfirst(static_cast<_This&&>(_Right._Myfirst))
		{
		}
	public:
		_This _Myfirst;
	};

	template<class _This, class _Rest>
	class Tuple<_This, _Rest>
		: private Tuple<_Rest>
	{
	public:
		typedef Tuple<_Rest> _Mybase;

	public:
		constexpr Tuple() noexcept
			:_Mybase()
		{
		}

		constexpr Tuple(_This&& _This_arg, _Rest&&  _resst_arg) noexcept
			:_Mybase(static_cast<_Rest&&>(_resst_arg)),
			_Myfirst(static_cast<_This&&>(_This_arg))
		{
		}

		//-------------------------------------------------

		Tuple(const Tuple<_This, _Rest>&) = default;
		//Tuple(Tuple<_This, _Rest>&) = default;

		constexpr Tuple(Tuple<_This&&, _Rest&&>&& _Right)
			:_Mybase(static_cast<_Rest&&>(Get<1>(_Right))),
			_Myfirst(static_cast<_This&&>(_Right._Myfirst))
		{
		}

	public:
		_This _Myfirst;
	};

	template<class _This, class _Rest, class _Rest1>
	class Tuple<_This, _Rest, _Rest1>
		: private Tuple<_Rest, _Rest1>
	{
	public:
		typedef _This _This_type;
		typedef Tuple<_Rest, _Rest1> _Mybase;

	public:
		constexpr Tuple() noexcept
			:_Mybase()
		{
		}

		constexpr Tuple(_This&& _This_arg, _Rest&&  _resst_arg, _Rest1&& _resst1_arg) noexcept
			:_Mybase(static_cast<_Rest&&>(_resst_arg), static_cast<_Rest1&&>(_resst1_arg)),
			_Myfirst(static_cast<_This&&>(_This_arg))
		{
		}

		//-------------------------------------------------

		Tuple(const Tuple<_This, _Rest, _Rest1>& _Right) = default;
		//Tuple(Tuple<_This, _Rest, _Rest1>&) = default;

		constexpr Tuple(Tuple<_This&&, _Rest&&, _Rest1&&>&& _Right)
			: _Mybase(static_cast<_Rest&&>(Get<1>(_Right)), static_cast<_Rest1&&>(Get<2>(_Right))),
			_Myfirst(static_cast<_This&&>(_Right._Myfirst))
		{
		}

	public:
		_This _Myfirst;
	};


// Wraps a piece of OpenGL state and remember its value to avoid redundant state calls.
// Wrapped types need to implement to the Value class interface:
//
// class Value {
//     using Type = ...;
//     static const constexpr Type Default = ...;
//     static void Set(const Type& value);
//     static Type Get();
// };
template <typename T, typename... Args>
class State {
public:
    State(Args&&... args) : params(Forward_as_Tuple(Forward<Args>(args)...)) {
    }

    void operator=(const typename T::Type& value) {
        if (*this != value) {
            setCurrentValue(value);
            set(std::index_sequence_for<Args...>{});
        }
    }

    bool operator==(const typename T::Type& value) const {
        return !(*this != value);
    }

    bool operator!=(const typename T::Type& value) const {
        return dirty || currentValue != value;
    }

    void setCurrentValue(const typename T::Type& value) {
        dirty = false;
        currentValue = value;
    }

    // Mark the state as dirty. This means that the next time we are assigning a value to this
    // piece of OpenGL state will always result in an actual OpenGL call.
    void setDirty() {
        dirty = true;
    }

    typename T::Type getCurrentValue() const {
        return currentValue;
    }

    bool isDirty() const {
        return dirty;
    }

private:
    template <std::size_t... I>
    void set(std::index_sequence<I...>) {
        T::Set(currentValue, Get<I>(params)...);
    }

private:
    typename T::Type currentValue = T::Default;
    bool dirty = true;
    const Tuple<Args...> params;
};

} // namespace gl
} // namespace mbgl
