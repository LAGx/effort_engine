#include "debug/logging/log.h"


using namespace eff::debug;
using namespace std;

Log::Log(Settings&& _settings, bool autoClear){
    setSettings(std::move(_settings));

    file_stream.open(settings.filepath, std::ofstream::out | std::ofstream::app);

    if(autoClear)
        clear();
}


void Log::setSettings(Settings&& _settings){
    settings = _settings;
    file_stream.close();
    file_stream.open(settings.filepath, std::ofstream::out | std::ofstream::app);
}


void Log::clear(){
    file_stream.open(settings.filepath, std::ofstream::out | std::ofstream::trunc);
}


Log::~Log(){
    file_stream.close();
}


string Log::makeTimeStr(){
    time.high_performance_tool.update();
    return to_string(time.high_performance_tool.get_core().tm_hour) + ":" + to_string(time.high_performance_tool.get_core().tm_min) + ":" + to_string(time.high_performance_tool.get_core().tm_sec);
}
