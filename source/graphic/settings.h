#pragma once
#include "graphic/meta.h"
#include "common_types/essential_types.h"
#include "common_types/common_settings.h"
#include "debug/logging/log.h"

namespace eff{
namespace graphic{
///settings of graphic module
namespace settings{

        ///logging settings block
        const bool ENABLE_INFO_LOGGING = true;
        const bool ENABLE_WARNING_LOGGING = true;
        const bool ENABLE_ERROR_LOGGING = true;

};

        debug::Log info_log(debug::Log::Settings({
                common_types::LOG_FOLDER_NAME + common_types::PATH_DELIMITER + "log_" + meta::MODULE_NAME + ".log"
                , false, settings::ENABLE_INFO_LOGGING}), true);

        debug::Log warning_log(debug::Log::Settings({
                common_types::LOG_FOLDER_NAME + common_types::PATH_DELIMITER + "warning_" + meta::MODULE_NAME + ".log"
                , false, settings::ENABLE_WARNING_LOGGING}), true);

        debug::Log error_log(debug::Log::Settings({
                common_types::LOG_FOLDER_NAME + common_types::PATH_DELIMITER + "error_" + meta::MODULE_NAME + ".log"
                , false, settings::ENABLE_ERROR_LOGGING}), true);
};
};
