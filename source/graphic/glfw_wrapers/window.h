#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <glm/vec2.hpp>
#include <memory>
#include "graphic/vulkan/core/surface.h"

using namespace std;


namespace eff{
namespace graphic{


/// class of glfw window and vulkan
class Window{
public:


    ////for creating window struct
    struct Settings{
        string name = "effort_engine_window"; ///name of window
        glm::vec2 size = {0,0};                                     /// size of window (by default {0,0} is fullscreen)
        glm::vec2 resolution = {0,0};                       ///resolution of window. work on fullscreen mode. {0,0}-default resolution
        bool isResizable = true;                               ///is can window be resize (don`t work in fullscreen mode)
    };


    Window(Settings settings);

    /*!
        @brief must to be using after constructor.
        delete old surface and create new based on new instance.
        @warning old instance must exist for correct deleting old surface
    */
    void setSurfaceInstance(VkInstance& surfaceInstance);


    /// get structure that used for init class
    const Settings& getSettings() const;

    ~Window();

protected:


    const Settings settings;
    GLFWwindow* g_window = nullptr;
    unique_ptr<Surface> surface = nullptr;
};



};
};
