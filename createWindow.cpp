#include <iostream>
#include <glfw3.h>
#include "createWindow.hpp"

namespace GameEngine {

    GLFWwindow *window;

    const uint16_t WIDTH = 800;
    const uint16_t HEIGHT = 600;

    static class createWindow {
    public:
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

        static void cleanup() {
            glfwDestroyWindow(window);
            glfwTerminate();
        }
    };
}