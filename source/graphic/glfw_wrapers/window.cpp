#include "graphic/glfw_wrapers/window.h"



using namespace std;
using namespace eff::graphic;


Window::Window(Window::Settings _settings): settings(move(_settings)){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    if(settings.isResizable)
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    if(settings.size == glm::vec2({0,0})){

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);

        if(settings.resolution == glm::vec2({0,0}))
            this->g_window = glfwCreateWindow(videoMode->width, videoMode->height, settings.name.c_str(), monitor, NULL);
        else
            this->g_window = glfwCreateWindow(settings.resolution.x, settings.resolution.y, settings.name.c_str(), monitor, NULL);

    }else{

        if(settings.isResizable)
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        this->g_window = glfwCreateWindow(settings.size.x, settings.size.y, settings.name.c_str() , nullptr, nullptr);
    }
}


const Window::Settings& Window::getSettings() const{
    return settings;
}


void Window::setSurfaceInstance(VkInstance& surfaceInstance){
    surface.reset(new Surface(surfaceInstance, g_window));
}


Window::~Window(){
    glfwDestroyWindow(g_window);
    glfwTerminate();
}
