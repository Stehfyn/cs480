// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

// @auth: Stephen Foster Oct '22 CS-480
// @repo: github.com/Stehfyn/cs480
// @assignment: 1.0
// @vers: 1.0
// @file: main.cpp

#pragma comment(lib, "opengl32")
#pragma comment(lib, "glew32")
#pragma comment(lib, "glfw3")
#pragma comment(lib, "soil2-debug")

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glew-2.1.0/glu.h> //Not wrangled by glew, see https://stackoverflow.com/a/3933593 && https://stackoverflow.com/a/73303899
#include <GL/GLU.h>           //Windows SDK, at "C:\Program Files\Microsoft SDKs\Windows\vX.XA\Include\gl", see https://stackoverflow.com/a/3933593

#include <iostream>

#include "engine.h"

int main(int argc, char** argv)
{
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
}