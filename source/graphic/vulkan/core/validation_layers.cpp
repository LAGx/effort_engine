#include "graphic/vulkan/core/validation_layers.h"

using namespace std;
using namespace eff::graphic;
using namespace eff::debug;


ValidationLayers::ValidationLayers(vector<string> validation_layers_list, VkDebugReportFlagsEXT debug_flags):
            validationLayersList(move(validation_layers_list)), flagsCallback(debug_flags) {

    if(auto error = isSupportAllLayers())
        warning_log << string() + "validation layer not avaiable.\n\t\terror layer: " + error.value();
    else
        info_log << "Validation layers pluged in.";

}



optional<string> ValidationLayers::isSupportAllLayers() const{

    optional<string> result;

    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    bool layerFound = 0;

    for (const string& layerName : validationLayersList) {
        layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (layerName == layerProperties.layerName) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
                result = layerName;
                return result;
        }
    }

    return nullopt;
}



VkResult ValidationLayers::resetInstanceCallback(VkInstance& instance){
    deleteInstanceCallback();

    parentInstance = &instance;
    VkDebugReportCallbackCreateInfoEXT createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    createInfo.flags = flagsCallback;
    createInfo.pfnCallback = debugCallback;

    auto CreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
    if (CreateDebugReportCallbackEXT != nullptr)
        return CreateDebugReportCallbackEXT(instance, &createInfo, nullptr, &callback);
    else
        return VK_ERROR_EXTENSION_NOT_PRESENT;
}


VKAPI_ATTR VkBool32 VKAPI_CALL  ValidationLayers::debugCallback(
        VkDebugReportFlagsEXT flags,
        VkDebugReportObjectTypeEXT objType,
        uint64_t obj,
        size_t location,
        int32_t code,
        const char* layerPrefix,
        const char* msg,
        void* userData
){

    info_log << string() + "was triggered vulkan debagCallback. type: " + string(layerPrefix);

    auto getInfo = [&]()->string{
        string info = "";
        info +=   ("\t\tobject type: " + to_string(objType));
        info += ("\n\t\tmessage: " + string(msg));
        return info;
    };

    switch(flags){
        case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:
            info_log << string() + " vulkan: \n" + getInfo();
            break;
        case VK_DEBUG_REPORT_WARNING_BIT_EXT:
            warning_log << string() + " vulkan: \n" + getInfo();
            break;
        case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT:
            warning_log << string() + " vulkan: non optimal use.\n" + getInfo();
            break;
        case VK_DEBUG_REPORT_ERROR_BIT_EXT:
            throw Exception(error_log, "vulkan: debugCallback\n" + getInfo());
            break;
        case VK_DEBUG_REPORT_DEBUG_BIT_EXT:
            info_log << string() + " vulkan: \n" + getInfo();
            break;
        default:
            throw InvalidArgumentException(error_log ,"underfined type of error: debugCallback\n");
    }

    return VK_FALSE;
}


void ValidationLayers::deleteInstanceCallback(){
    if(parentInstance != nullptr){
        auto _vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(*parentInstance, "vkDestroyDebugReportCallbackEXT");
        if (_vkDestroyDebugReportCallbackEXT != nullptr)
            _vkDestroyDebugReportCallbackEXT(*parentInstance, callback, nullptr);
        parentInstance = nullptr;
    }
}


vector<string> ValidationLayers::getLayersList() const{
    return this->validationLayersList;
}


ValidationLayers::~ValidationLayers(){
    deleteInstanceCallback();
}
