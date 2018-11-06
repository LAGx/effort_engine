#pragma once
#include "graphic/common/meta.h"
#include "common_types/essential_types.h"
#include "common_types/common_settings.h"
#include "debug/logging/log.h"

namespace eff{
namespace graphic{
///settings of graphic module
namespace settings{

        ///logging settings block
        extern const bool ENABLE_INFO_LOGGING;
        extern const bool ENABLE_WARNING_LOGGING;
        extern const bool ENABLE_ERROR_LOGGING;

};

        extern debug::Log info_log;
        extern debug::Log warning_log;
        extern debug::Log error_log;

};
};
