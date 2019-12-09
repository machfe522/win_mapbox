#include <mbgl/style/types.hpp>
#include <mbgl/util/enum.hpp>

namespace mbgl {

using namespace style;

/*
MBGL_DEFINE_ENUM(SourceType, {
    { SourceType::Vector, "vector" },
    { SourceType::Raster, "raster" },
    { SourceType::GeoJSON, "geojson" },
    { SourceType::Video, "video" },
    { SourceType::Annotations, "annotations" },
    { SourceType::Image, "image" },
    { SourceType::CustomVector, "customvector" }
});
*/
static const constexpr std::pair<const SourceType, const char *> SourceType_names[] = {
	{ SourceType::Vector, "vector" },
	{ SourceType::Raster, "raster" },
	{ SourceType::GeoJSON, "geojson" },
	{ SourceType::Video, "video" },
	{ SourceType::Annotations, "annotations" },
	{ SourceType::Image, "image" },
	{ SourceType::CustomVector, "customvector" }
};
                                                                               
template <>                                                                    
const char * Enum<SourceType>::toString(SourceType t) {
    auto it = std::find_if(std::begin(SourceType_names), std::end(SourceType_names),
        [&] (const auto& v) { return t == v.first; });                         
    assert(it != std::end(SourceType_names)); return it->second;
}                                                                              
                                                                               
template <>                                                                    
optional<SourceType> Enum<SourceType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(SourceType_names), std::end(SourceType_names),
        [&] (const auto& v) { return s == v.second; });                        
    return it == std::end(SourceType_names) ? optional<SourceType>() : it->first;
}



/*
MBGL_DEFINE_ENUM(VisibilityType, {
    { VisibilityType::Visible, "visible" },
    { VisibilityType::None, "none" },
});*/

static const constexpr std::pair<const VisibilityType, const char *> VisibilityType_names[] = {
	{ VisibilityType::Visible, "visible" },
	{ VisibilityType::None, "none" },
};
                                                                               
template <>                                                                    
const char * Enum<VisibilityType>::toString(VisibilityType t) {
    auto it = std::find_if(std::begin(VisibilityType_names), std::end(VisibilityType_names),
        [&] (const auto& v) { return t == v.first; });                         
    assert(it != std::end(VisibilityType_names)); return it->second;
}                                                                              
                                                                               
template <>                                                                    
optional<VisibilityType> Enum<VisibilityType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(VisibilityType_names), std::end(VisibilityType_names),
        [&] (const auto& v) { return s == v.second; });                        
    return it == std::end(VisibilityType_names) ? optional<VisibilityType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(TranslateAnchorType, {
    { TranslateAnchorType::Map, "map" },
    { TranslateAnchorType::Viewport, "viewport" },
});
*/

static const constexpr std::pair<const TranslateAnchorType, const char *> TranslateAnchorType_names[] = {
	{ TranslateAnchorType::Map, "map" },
	{ TranslateAnchorType::Viewport, "viewport" },
};
                                                                              
template <>                                                                   
const char * Enum<TranslateAnchorType>::toString(TranslateAnchorType t) {
    auto it = std::find_if(std::begin(TranslateAnchorType_names), std::end(TranslateAnchorType_names),
        [&] (const auto& v) { return t == v.first; });                        
    assert(it != std::end(TranslateAnchorType_names)); return it->second;
}                                                                             
                                                                              
template <>                                                                   
optional<TranslateAnchorType> Enum<TranslateAnchorType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(TranslateAnchorType_names), std::end(TranslateAnchorType_names),
        [&] (const auto& v) { return s == v.second; });                       
    return it == std::end(TranslateAnchorType_names) ? optional<TranslateAnchorType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(RasterResamplingType, {
    { RasterResamplingType::Linear, "linear" },
    { RasterResamplingType::Nearest, "nearest" },
});
*/

static const constexpr std::pair<const RasterResamplingType, const char *> RasterResamplingType_names[] = {
	{ RasterResamplingType::Linear, "linear" },
	{ RasterResamplingType::Nearest, "nearest" },
};
                                                                               
template <>                                                                    
const char * Enum<RasterResamplingType>::toString(RasterResamplingType t) {
    auto it = std::find_if(std::begin(RasterResamplingType_names), std::end(RasterResamplingType_names),
        [&] (const auto& v) { return t == v.first; });                         
    assert(it != std::end(RasterResamplingType_names)); return it->second;
}                                                                              
                                                                               
template <>                                                                    
optional<RasterResamplingType> Enum<RasterResamplingType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(RasterResamplingType_names), std::end(RasterResamplingType_names),
        [&] (const auto& v) { return s == v.second; });                        
    return it == std::end(RasterResamplingType_names) ? optional<RasterResamplingType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(HillshadeIlluminationAnchorType, {
    { HillshadeIlluminationAnchorType::Map, "map" },
    { HillshadeIlluminationAnchorType::Viewport, "viewport" },
});
*/
static const constexpr std::pair<const HillshadeIlluminationAnchorType, const char *> HillshadeIlluminationAnchorType_names[] = {
	{ HillshadeIlluminationAnchorType::Map, "map" },
	{ HillshadeIlluminationAnchorType::Viewport, "viewport" },
};
                                                                                
template <>                                                                     
const char * Enum<HillshadeIlluminationAnchorType>::toString(HillshadeIlluminationAnchorType t) {
    auto it = std::find_if(std::begin(HillshadeIlluminationAnchorType_names), std::end(HillshadeIlluminationAnchorType_names),
        [&] (const auto& v) { return t == v.first; });                          
    assert(it != std::end(HillshadeIlluminationAnchorType_names)); return it->second;
}                                                                               
                                                                                
template <>                                                                     
optional<HillshadeIlluminationAnchorType> Enum<HillshadeIlluminationAnchorType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(HillshadeIlluminationAnchorType_names), std::end(HillshadeIlluminationAnchorType_names),
        [&] (const auto& v) { return s == v.second; });                         
    return it == std::end(HillshadeIlluminationAnchorType_names) ? optional<HillshadeIlluminationAnchorType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(RotateAnchorType, {
    { RotateAnchorType::Map, "map" },
    { RotateAnchorType::Viewport, "viewport" },
});
*/

static const constexpr std::pair<const RotateAnchorType, const char *> RotateAnchorType_names[] = {
	{ RotateAnchorType::Map, "map" },
	{ RotateAnchorType::Viewport, "viewport" },
};
                                                                                 
template <>                                                                      
const char * Enum<RotateAnchorType>::toString(RotateAnchorType t) {
    auto it = std::find_if(std::begin(RotateAnchorType_names), std::end(RotateAnchorType_names),
        [&] (const auto& v) { return t == v.first; });                           
    assert(it != std::end(RotateAnchorType_names)); return it->second;
}                                                                                
                                                                                 
template <>                                                                      
optional<RotateAnchorType> Enum<RotateAnchorType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(RotateAnchorType_names), std::end(RotateAnchorType_names),
        [&] (const auto& v) { return s == v.second; });                          
    return it == std::end(RotateAnchorType_names) ? optional<RotateAnchorType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(CirclePitchScaleType, {
    { CirclePitchScaleType::Map, "map" },
    { CirclePitchScaleType::Viewport, "viewport" },
});
*/

static const constexpr std::pair<const CirclePitchScaleType, const char *> CirclePitchScaleType_names[] = {
	{ CirclePitchScaleType::Map, "map" },
	{ CirclePitchScaleType::Viewport, "viewport" },
};

template <>
const char * Enum<CirclePitchScaleType>::toString(CirclePitchScaleType t) {
	auto it = std::find_if(std::begin(CirclePitchScaleType_names), std::end(CirclePitchScaleType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(CirclePitchScaleType_names)); return it->second;
}

template <>
optional<CirclePitchScaleType> Enum<CirclePitchScaleType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(CirclePitchScaleType_names), std::end(CirclePitchScaleType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(CirclePitchScaleType_names) ? optional<CirclePitchScaleType>() : it->first;
}

/*MBGL_DEFINE_ENUM(LineCapType, {
    { LineCapType::Round, "round" },
    { LineCapType::Butt, "butt" },
    { LineCapType::Square, "square" },
});
*/

static const constexpr std::pair<const LineCapType, const char *> LineCapType_names[] = {
	{ LineCapType::Round, "round" },
	{ LineCapType::Butt, "butt" },
	{ LineCapType::Square, "square" },
};

template <>
const char * Enum<LineCapType>::toString(LineCapType t) {
	auto it = std::find_if(std::begin(LineCapType_names), std::end(LineCapType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(LineCapType_names)); return it->second;
}

template <>
optional<LineCapType> Enum<LineCapType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(LineCapType_names), std::end(LineCapType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(LineCapType_names) ? optional<LineCapType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(LineJoinType, {
    { LineJoinType::Miter, "miter" },
    { LineJoinType::Bevel, "bevel" },
    { LineJoinType::Round, "round" },
    { LineJoinType::FakeRound, "fakeround" },
    { LineJoinType::FlipBevel, "flipbevel" },
});
*/

static const constexpr std::pair<const LineJoinType, const char *> LineJoinType_names[] = {
	{ LineJoinType::Miter, "miter" },
	{ LineJoinType::Bevel, "bevel" },
	{ LineJoinType::Round, "round" },
	{ LineJoinType::FakeRound, "fakeround" },
	{ LineJoinType::FlipBevel, "flipbevel" },
};

template <>
const char * Enum<LineJoinType>::toString(LineJoinType t) {
	auto it = std::find_if(std::begin(LineJoinType_names), std::end(LineJoinType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(LineJoinType_names)); return it->second;
}

template <>
optional<LineJoinType> Enum<LineJoinType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(LineJoinType_names), std::end(LineJoinType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(LineJoinType_names) ? optional<LineJoinType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(SymbolPlacementType, {
    { SymbolPlacementType::Point, "point" },
    { SymbolPlacementType::Line, "line" },
    { SymbolPlacementType::LineCenter, "line-center" },
});
*/

static const constexpr std::pair<const SymbolPlacementType, const char *> SymbolPlacementType_names[] = {
	{ SymbolPlacementType::Point, "point" },
	{ SymbolPlacementType::Line, "line" },
	{ SymbolPlacementType::LineCenter, "line-center" },
};

template <>
const char * Enum<SymbolPlacementType>::toString(SymbolPlacementType t) {
	auto it = std::find_if(std::begin(SymbolPlacementType_names), std::end(SymbolPlacementType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(SymbolPlacementType_names)); return it->second;
}

template <>
optional<SymbolPlacementType> Enum<SymbolPlacementType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(SymbolPlacementType_names), std::end(SymbolPlacementType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(SymbolPlacementType_names) ? optional<SymbolPlacementType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(SymbolAnchorType, {
    { SymbolAnchorType::Center, "center" },
    { SymbolAnchorType::Left, "left" },
    { SymbolAnchorType::Right, "right" },
    { SymbolAnchorType::Top, "top" },
    { SymbolAnchorType::Bottom, "bottom" },
    { SymbolAnchorType::TopLeft, "top-left" },
    { SymbolAnchorType::TopRight, "top-right" },
    { SymbolAnchorType::BottomLeft, "bottom-left" },
    { SymbolAnchorType::BottomRight, "bottom-right" }
});
*/

static const constexpr std::pair<const SymbolAnchorType, const char *> SymbolAnchorType_names[] = {
	{ SymbolAnchorType::Center, "center" },
	{ SymbolAnchorType::Left, "left" },
	{ SymbolAnchorType::Right, "right" },
	{ SymbolAnchorType::Top, "top" },
	{ SymbolAnchorType::Bottom, "bottom" },
	{ SymbolAnchorType::TopLeft, "top-left" },
	{ SymbolAnchorType::TopRight, "top-right" },
	{ SymbolAnchorType::BottomLeft, "bottom-left" },
	{ SymbolAnchorType::BottomRight, "bottom-right" }
};

template <>
const char * Enum<SymbolAnchorType>::toString(SymbolAnchorType t) {
	auto it = std::find_if(std::begin(SymbolAnchorType_names), std::end(SymbolAnchorType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(SymbolAnchorType_names)); return it->second;
}

template <>
optional<SymbolAnchorType> Enum<SymbolAnchorType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(SymbolAnchorType_names), std::end(SymbolAnchorType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(SymbolAnchorType_names) ? optional<SymbolAnchorType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(SymbolZOrderType, {
    { SymbolZOrderType::Auto, "auto" },
    { SymbolZOrderType::ViewportY, "viewport-y" },
    { SymbolZOrderType::Source, "source" }
});
*/

static const constexpr std::pair<const SymbolZOrderType, const char *> SymbolZOrderType_names[] = {
	{ SymbolZOrderType::Auto, "auto" },
	{ SymbolZOrderType::ViewportY, "viewport-y" },
	{ SymbolZOrderType::Source, "source" }
};

template <>
const char * Enum<SymbolZOrderType>::toString(SymbolZOrderType t) {
	auto it = std::find_if(std::begin(SymbolZOrderType_names), std::end(SymbolZOrderType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(SymbolZOrderType_names)); return it->second;
}

template <>
optional<SymbolZOrderType> Enum<SymbolZOrderType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(SymbolZOrderType_names), std::end(SymbolZOrderType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(SymbolZOrderType_names) ? optional<SymbolZOrderType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(TextJustifyType, {
    { TextJustifyType::Auto, "auto" },
    { TextJustifyType::Center, "center" },
    { TextJustifyType::Left, "left" },
    { TextJustifyType::Right, "right" },
});
*/

static const constexpr std::pair<const TextJustifyType, const char *> TextJustifyType_names[] = {
	{ TextJustifyType::Auto, "auto" },
	{ TextJustifyType::Center, "center" },
	{ TextJustifyType::Left, "left" },
	{ TextJustifyType::Right, "right" },
};

template <>
const char * Enum<TextJustifyType>::toString(TextJustifyType t) {
	auto it = std::find_if(std::begin(TextJustifyType_names), std::end(TextJustifyType_names),
		[&](const auto& v) { return t == v.first; });
	assert(it != std::end(TextJustifyType_names)); return it->second;
}

template <>
optional<TextJustifyType> Enum<TextJustifyType>::toEnum(const std::string& s) {
	auto it = std::find_if(std::begin(TextJustifyType_names), std::end(TextJustifyType_names),
		[&](const auto& v) { return s == v.second; });
	return it == std::end(TextJustifyType_names) ? optional<TextJustifyType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(TextTransformType, {
    { TextTransformType::None, "none" },
    { TextTransformType::Uppercase, "uppercase" },
    { TextTransformType::Lowercase, "lowercase" },
});
*/

static const constexpr std::pair<const TextTransformType, const char *> TextTransformType_names[] = {
	{ TextTransformType::None, "none" },
	{ TextTransformType::Uppercase, "uppercase" },
	{ TextTransformType::Lowercase, "lowercase" },
};

                                                                                 
template <>                                                                      
const char * Enum<TextTransformType>::toString(TextTransformType t) {
    auto it = std::find_if(std::begin(TextTransformType_names), std::end(TextTransformType_names),
        [&] (const auto& v) { return t == v.first; });                           
    assert(it != std::end(TextTransformType_names)); return it->second;
}                                                                                
                                                                                 
template <>                                                                      
optional<TextTransformType> Enum<TextTransformType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(TextTransformType_names), std::end(TextTransformType_names),
        [&] (const auto& v) { return s == v.second; });                          
    return it == std::end(TextTransformType_names) ? optional<TextTransformType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(AlignmentType, {
    { AlignmentType::Map, "map" },
    { AlignmentType::Viewport, "viewport" },
    { AlignmentType::Auto, "auto" },
});
*/
static const constexpr std::pair<const AlignmentType, const char *> AlignmentType_names[] = {
	{ AlignmentType::Map, "map" },
	{ AlignmentType::Viewport, "viewport" },
	{ AlignmentType::Auto, "auto" },
};
                                                                                 
template <>                                                                      
const char * Enum<AlignmentType>::toString(AlignmentType t) {
    auto it = std::find_if(std::begin(AlignmentType_names), std::end(AlignmentType_names),
        [&] (const auto& v) { return t == v.first; });                           
    assert(it != std::end(AlignmentType_names)); return it->second;
}                                                                                
                                                                                 
template <>                                                                      
optional<AlignmentType> Enum<AlignmentType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(AlignmentType_names), std::end(AlignmentType_names),
        [&] (const auto& v) { return s == v.second; });                          
    return it == std::end(AlignmentType_names) ? optional<AlignmentType>() : it->first;
}

/*
MBGL_DEFINE_ENUM(IconTextFitType, {
    { IconTextFitType::None, "none" },
    { IconTextFitType::Both, "both" },
    { IconTextFitType::Width, "width" },
    { IconTextFitType::Height, "height" },
});
*/
static const constexpr std::pair<const IconTextFitType, const char *> IconTextFitType_names[] = {
	{ IconTextFitType::None, "none" },
	{ IconTextFitType::Both, "both" },
	{ IconTextFitType::Width, "width" },
	{ IconTextFitType::Height, "height" },
};
                                                                                 
template <>                                                                      
const char * Enum<IconTextFitType>::toString(IconTextFitType t) {
    auto it = std::find_if(std::begin(IconTextFitType_names), std::end(IconTextFitType_names),
        [&] (const auto& v) { return t == v.first; });                           
    assert(it != std::end(IconTextFitType_names)); return it->second;
}                                                                                
                                                                                 
template <>                                                                      
optional<IconTextFitType> Enum<IconTextFitType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(IconTextFitType_names), std::end(IconTextFitType_names),
        [&] (const auto& v) { return s == v.second; });                          
    return it == std::end(IconTextFitType_names) ? optional<IconTextFitType>() : it->first;
}

																		  

/*
MBGL_DEFINE_ENUM(LightAnchorType, {
    { LightAnchorType::Map, "map" },
    { LightAnchorType::Viewport, "viewport" }
});
*/

static const constexpr std::pair<const LightAnchorType, const char *> LightAnchorType_names[] = {
	{ LightAnchorType::Map, "map" },
	{ LightAnchorType::Viewport, "viewport" }
};
                                                                                
template <>                                                                     
const char * Enum<LightAnchorType>::toString(LightAnchorType t) {
    auto it = std::find_if(std::begin(LightAnchorType_names), std::end(LightAnchorType_names),
        [&] (const auto& v) { return t == v.first; });                          
    assert(it != std::end(LightAnchorType_names)); return it->second;
}                                                                               
                                                                                
template <>                                                                     
optional<LightAnchorType> Enum<LightAnchorType>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(LightAnchorType_names), std::end(LightAnchorType_names),
        [&] (const auto& v) { return s == v.second; });                         
    return it == std::end(LightAnchorType_names) ? optional<LightAnchorType>() : it->first;
}

} // namespace mbgl
