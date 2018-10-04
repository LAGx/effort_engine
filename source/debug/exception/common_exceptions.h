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

    protected:

        std::string reason;

    };


    class InitException: public Exception{
    public:
        ///use this conctructor for writing about exception in log
        InitException( Log& log_object, std::string reason);

        ///use this constructor for just save reason
        InitException(std::string reason);
    };


};
};
