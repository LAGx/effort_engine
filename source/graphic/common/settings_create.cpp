#include "graphic/common/meta.h"
#include "graphic/common/settings.h"




namespace eff{
namespace graphic{
///settings of graphic module

namespace meta{

        const std::string MODULE_NAME = "GRAPHIC";
        const std::string VERSION = "0.0.2 alpha";

};

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
