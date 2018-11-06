#pragma once
#include <vector>
#include <string>
#include <optional>
#include "vulkan/vulkan.h"
#include "debug/exception/common_exceptions.h"
#include "graphic/common/settings.h"

namespace eff{
namespace graphic{

/*!
    @breif class for creating validation layers
    @warning instance must exist while class exist for correct deleting layers
*/
class ValidationLayers{
public:

    ValidationLayers( std::vector<std::string> validation_layers_list, VkDebugReportFlagsEXT debug_flags);

    std::vector<std::string> getLayersList() const;

    VkResult resetInstanceCallback(VkInstance& instance);

    ~ValidationLayers();

private:

    std::optional<std::string> isSupportAllLayers() const;

    void deleteInstanceCallback();


    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
                VkDebugReportFlagsEXT flags,
                VkDebugReportObjectTypeEXT objType,
                uint64_t obj,
                size_t location,
                int32_t code,
                const char* layerPrefix,
                const char* msg,
                void* userData
            );

    VkInstance*  parentInstance = nullptr;
    std::vector<std::string> validationLayersList;
    VkDebugReportFlagsEXT flagsCallback;
    VkDebugReportCallbackEXT callback;

};

};
};
