#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <glfw3.h>
#include <vector>

namespace GameEngine {
    GLFWwindow *window;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    void initWindow() {

        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(HEIGHT, WIDTH, "My Window, Wow!", nullptr, nullptr);
    }

    static void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }
}