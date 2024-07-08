#include <iostream>
#include "createWindow.cpp"

#define GLFW_INCLUDE_VULKAN

using std::exception, std::cerr;

namespace GameEngine {
    class runApplication {
    public:
        void run() {
            initVulkan();
            GameEngine::createWindow::mainLoop();
            createWindow::cleanup();
        }

    private:
        void initVulkan() {

        }
    };

    int main() {
        runApplication app;

        try {
            app.run();
        }
        catch (const exception& error) {
            cerr << error.what() << "/n";
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}