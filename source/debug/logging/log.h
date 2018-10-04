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
@brief class for logging
*/
class Log {
public:

    ///settings
    struct Settings{
        /// relative path for log path
        std::string filepath = std::string("log") + common_types::PATH_DELIMITER + "Log.log";
        /// is writing current time of logging
        bool write_time = true;
    };

    /*
    @param autoClear is clear file on open
    */
    Log(Settings&&, bool autoClear = true);

    ///set settings
    void setSettings(Settings&&);

    ///clear current file
    void clear();

    /*!
    input[in] log operator

    <B>example:</B>
    @code
    Log log(Log::Settings({"log.log", false}), true);
    log << "hello";
    log.setSettings(Log::Settings({"log.log", true}));
    log << "world";

    // output (log.log):
    // |> hello
    // |16:33:19|> world
    @endcode
    */
    template <typename T>
    Log& operator<<(T const& value){

        file_stream << (settings.write_time ? "|" + makeTimeStr() : "");
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
