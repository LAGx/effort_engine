#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include "common_types/essential_types.h"

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
                file_stream << value;
                return *this;
        }

        ~Log();

private:

        Settings settings;

        std::string makeTimeStr();

        std::time_t rawtime;
        std::tm timeinfo;
        std::ofstream file_stream;
};


}
}
