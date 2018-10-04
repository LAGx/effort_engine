#include "graphic/vulkan/core/surface.h"
#include "graphic/settings.h"

using namespace std;
using namespace eff::graphic;
using namespace eff::debug;

extern Log error_log;


Surface::Surface(VkInstance& instance, GLFWwindow* window):parentInstance(instance){
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)
            throw InitException(error_log, "failed to create surface!");
}


Surface::~Surface(){
    vkDestroySurfaceKHR(parentInstance, surface, nullptr);
}
