#include "debug/logging/log.h"


using namespace eff::debug;
using namespace std;

Log::Log(Settings&& _settings, bool autoClear){
        setSettings(std::move(_settings));

        if(autoClear)
                clear();

        throw 0; //NOT WORKING LOGGING!!!
}


void Log::setSettings(Settings&& _settings){
        settings = _settings;
}


void Log::clear(){

}


Log::~Log(){

}


string Log::makeTimeStr(){
        //rawtime = time(0);

        //std::chrono::system_clock::now().time_since_epoch().count();




        return to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
}
