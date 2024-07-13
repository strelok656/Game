#include "createWindow.cpp"
#include "createInstance.cpp"
#include <vector>

using std::exception, std::cerr;

namespace GameEngine {
    

    class runApplication {
    public:
        static void cleanup() {
            vkDestroyInstance(instance, nullptr);
            glfwDestroyWindow(window);
            glfwTerminate();
        }

        void run() {
            initVulkan();
            mainLoop();
            cleanup();
        }

    };

    int main() {
        GameEngine::runApplication app;

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