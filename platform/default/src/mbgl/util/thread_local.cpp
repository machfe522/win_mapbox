#include <mbgl/util/thread_local.hpp>
#include <mbgl/util/logging.hpp>

#include <cassert>
#include <cstdlib>

#include <windows.h>

namespace mbgl {
namespace util {
namespace impl {

 
ThreadLocalBase::ThreadLocalBase() {
    static_assert(sizeof(storage) >= sizeof(DWORD), "storage is too small");
    static_assert(alignof(decltype(storage)) % alignof(DWORD) == 0, "storage is incorrectly aligned");
	new (&reinterpret_cast<DWORD&>(storage))DWORD(TlsAlloc());
	if (reinterpret_cast<DWORD&>(storage) == TLS_OUT_OF_INDEXES) {
        Log::Error(Event::General, "Failed to initialize thread-specific storage key");
       abort();
    }
}

ThreadLocalBase::~ThreadLocalBase() {
    // ThreadLocal will not take ownership of the pointer it is managing. The pointer
    // needs to be explicitly cleared before we destroy this object.
    assert(!get());

    if (!TlsFree(reinterpret_cast<DWORD&>(storage))) {
       Log::Error(Event::General, "Failed to delete thread-specific storage key");
       abort();
    }
}

void* ThreadLocalBase::get() {
	return  TlsGetValue(reinterpret_cast<DWORD&>(storage));
}

void ThreadLocalBase::set(void* ptr) {	 
    if (!TlsSetValue(reinterpret_cast<DWORD&>(storage), ptr)) {
        Log::Error(Event::General, "Failed to set thread-specific storage");
        abort();
    }
}

} // namespace impl
} // namespace util
} // namespace mbgl
