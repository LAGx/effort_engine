#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include "common_types/essential_types.h"
#include "common_types/local_time/date_time.h"


namespace eff{
namespace debug{

/*
*@brief class for logging
*/
class Log {
public:

    struct Settings{
            std::string filepath = std::string("log") + common_types::PATH_DELIMITER + "Log.log";
            bool write_time = true;
    };

    Log(Settings&&, bool autoClear = true);

    void setSettings(Settings&&);

    void clear();

    template <typename T>
    Log& operator<<(T const& value){

        file_stream << (settings.write_time ? makeTimeStr() : "");
        file_stream << "|> ";
        file_stream << value;
        file_stream << std::endl;

        return *this;
    }

    ~Log();

private:

    std::string makeTimeStr();

    std::ofstream file_stream;
    Settings settings;
    common_types::DateTime time;
};


}
}
