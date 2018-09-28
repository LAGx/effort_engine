#include "date_time.h"


using namespace eff::common_types;
using namespace std;
using namespace std::chrono;



unsigned int DateTime::operator()(DateTime::TimeType _timeType){

    high_performance_tool.update();
    unsigned int f_time;

    switch(_timeType){
        case (TimeType::Second):
            f_time = timeinfo->tm_sec;
            break;
        case (TimeType::Minute):
            f_time = timeinfo->tm_min;
            break;
        case (TimeType::Hour):
            f_time = timeinfo->tm_hour;
            break;
        case (TimeType::Day):
            f_time = timeinfo->tm_mday;
            break;
        case (TimeType::Month):
            f_time = timeinfo->tm_mon+1;
            break;
        case (TimeType::Year):
            f_time = timeinfo->tm_year+1900;
            break;
    }

    return f_time;
}


void DateTime::decltype(DateTime::high_performance_tool)::update(){
    parent.rawtime = system_clock::to_time_t(std::chrono::system_clock::now());
    gmtime_r(&parent.rawtime, parent.timeinfo);
}


tm& DateTime::decltype(DateTime::high_performance_tool)::get_core() const{
    return *(parent.timeinfo);
}
