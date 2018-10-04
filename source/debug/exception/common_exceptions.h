#pragma once
#include <string>
#include <utility>
#include "debug/logging/log.h"


namespace eff{
namespace debug{


    /// base effort exception
    class Exception{
    public:

        ///use this conctructor for writing about exception in log
        Exception( Log& log_object, std::string reason);

        ///use this constructor for just save reason
        Exception(std::string reason);

        std::string what() const;

    private:

        std::string reason;

    };


};
};
