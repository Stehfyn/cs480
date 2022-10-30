// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "Base.h"
#ifdef BUILD_WITH_IMGUI
#include "PA2ImGui.h"
int main(int, char**)
{
    auto app = PA2ImGui("PA2", 1280, 720);
    app.Run();
    return 0;
}
#else
#include "GLFWApplication.h"
int main(int argc, char** argv)
{
    /*
    // Start an engine and run it then cleanup after

    // Create the engine
    Engine* engine = new Engine("Tutorial Window Name", 800, 600);

    // Engine initialization

    if (!engine->Initialize()) {
        printf("The engine failed to start.\n");
        delete engine;
        engine = NULL;
        return 1;
    }

    // Run the engine
    engine->Run();

    // Destroy the engine
    delete engine;
    engine = NULL;

    return 0;
    */

    try
    {
        auto app = ImGuiApplication();
        app.Run();
        std::exit(0);
    }
    catch (const std::exception e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }
}
#endif