#pragma once
#include <GLFW/glfw3.h>
#include "graphic/common/settings.h"
#include "debug/exception/common_exceptions.h"
#include "vulkan/vulkan.h"

namespace eff{
namespace graphic{


/*!
    @breif class of surface
    @warning instance must exist while class exist for correct deleting surface
*/
class Surface{
public:

    Surface(VkInstance &instance, GLFWwindow *window);

    ~Surface();

protected:

    VkInstance &parentInstance;
    VkSurfaceKHR surface;

};

};
};
