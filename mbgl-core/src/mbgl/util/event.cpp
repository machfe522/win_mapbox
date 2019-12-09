#include <mbgl/util/event.hpp>
#include <mbgl/util/enum.hpp>

namespace mbgl {

	                                                                              
static const constexpr std::pair<const EventSeverity, const char *> EventSeverity_names[] = {
	{ EventSeverity::Debug, "DEBUG" },
	{ EventSeverity::Info, "INFO" },
	{ EventSeverity::Warning, "WARNING" },
	{ EventSeverity::Error, "ERROR" },
	{ EventSeverity(-1), "UNKNOWN" },
																				 };    
                                                                                 
template <>                                                                      
const char * Enum<EventSeverity>::toString(EventSeverity t) {
    auto it = std::find_if(std::begin(EventSeverity_names), std::end(EventSeverity_names),           
        [&] (const auto& v) { return t == v.first; });                           
    assert(it != std::end(EventSeverity_names)); return it->second;                       
}                                                                                
                                                                                 
template <>                                                                      
optional<EventSeverity> Enum<EventSeverity>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(EventSeverity_names), std::end(EventSeverity_names),           
        [&] (const auto& v) { return s == v.second; });                          
    return it == std::end(EventSeverity_names) ? optional<EventSeverity>() : it->first;
}

//===============================================================

static const constexpr std::pair<const Event, const char *> Event_names[] = {
	{ Event::General, "General" },
	{ Event::Setup, "Setup" },
	{ Event::Shader, "Shader" },
	{ Event::ParseStyle, "ParseStyle" },
	{ Event::ParseTile, "ParseTile" },
	{ Event::Render, "Render" },
	{ Event::Style, "Style" },
	{ Event::Database, "Database" },
	{ Event::HttpRequest, "HttpRequest" },
	{ Event::Sprite, "Sprite" },
	{ Event::Image, "Image" },
	{ Event::OpenGL, "OpenGL" },
	{ Event::JNI, "JNI" },
	{ Event::Android, "Android" },
	{ Event::Crash, "Crash" },
	{ Event::Glyph, "Glyph" },
	{ Event::Timing, "Timing" },
	{ Event(-1), "Unknown" },
};
                                                                              
template <>                                                                   
const char * Enum<Event>::toString(Event t) {
    auto it = std::find_if(std::begin(Event_names), std::end(Event_names),
        [&] (const auto& v) { return t == v.first; });                        
    assert(it != std::end(Event_names)); return it->second;
}                                                                             
                                                                              
template <>                                                                   
optional<Event> Enum<Event>::toEnum(const std::string& s) {
    auto it = std::find_if(std::begin(Event_names), std::end(Event_names),
        [&] (const auto& v) { return s == v.second; });                       
    return it == std::end(Event_names) ? optional<Event>() : it->first;
}

//===============================================================
/*

MBGL_DEFINE_ENUM(EventSeverity, {
	{ EventSeverity::Debug, "DEBUG" },
	{ EventSeverity::Info, "INFO" },
	{ EventSeverity::Warning, "WARNING" },
	{ EventSeverity::Error, "ERROR" },
	{ EventSeverity(-1), "UNKNOWN" },
});

MBGL_DEFINE_ENUM(Event, {
	{ Event::General, "General" },
	{ Event::Setup, "Setup" },
	{ Event::Shader, "Shader" },
	{ Event::ParseStyle, "ParseStyle" },
	{ Event::ParseTile, "ParseTile" },
	{ Event::Render, "Render" },
	{ Event::Style, "Style" },
	{ Event::Database, "Database" },
	{ Event::HttpRequest, "HttpRequest" },
	{ Event::Sprite, "Sprite" },
	{ Event::Image, "Image" },
	{ Event::OpenGL, "OpenGL" },
	{ Event::JNI, "JNI" },
	{ Event::Android, "Android" },
	{ Event::Crash, "Crash" },
	{ Event::Glyph, "Glyph" },
	{ Event::Timing, "Timing" },
	{ Event(-1), "Unknown" },
});

*/

} // namespace mbgl
