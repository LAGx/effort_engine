#pragma once
#include "debug/meta.h"


namespace eff{
///main namespace of engine module
namespace debug{
///settings of debug module
namespace settings{

        ///logging settings block
        constexpr bool ENABLE_ALL_LOGGING = true;
        const std::string log_filename = "log_" + meta::MODULE_NAME + ".log";
        const std::string warning_filename = "warning_" + meta::MODULE_NAME + ".log";
        const std::string error_filename = "error_" + meta::MODULE_NAME + ".log";

};
};
};
