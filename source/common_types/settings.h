#pragma once
#include "common_types/meta.h"



namespace eff{
namespace common_types{
namespace settings{

        //logging
        constexpr bool ENABLE_ALL_LOGGING = true; 
        const std::string log_filename = "log_" + meta::MODULE_NAME + ".log";
        const std::string warning_filename = "warning_" + meta::MODULE_NAME + ".log";
        const std::string error_filename = "error_" + meta::MODULE_NAME + ".log";

};
};
};