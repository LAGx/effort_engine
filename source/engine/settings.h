#pragma once
#include "engine/meta.h"

///main namespace of all project
namespace eff{
///main namespace of engine module
namespace engine{
///settings of engine module
namespace settings{

        ///logging settings block
        constexpr bool ENABLE_ALL_LOGGING = true;
        const std::string log_filename = "log_" + meta::MODULE_NAME + ".log";
        const std::string warning_filename = "warning_" + meta::MODULE_NAME + ".log";
        const std::string error_filename = "error_" + meta::MODULE_NAME + ".log";

};
};
};
