#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <exception>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "glfw_callbacks.h"		  // Regardless of entry point or imgui usage, we use glfw and thus must register callbacks. These are the callback definitions

#ifdef BUILD_WITH_IMGUI
	#pragma comment(lib, "opengl32")
	#pragma comment(lib, "glew32")
	#pragma comment(lib, "glfw3")
	
	#include <GL/glew.h>
	#include <imgui/imgui.h>
	#include <imgui/backends/imgui_impl_glfw.h>
	#include <imgui/backends/imgui_impl_opengl3.h>
	#include <stdio.h>
	#define GL_SILENCE_DEPRECATION
	#if defined(IMGUI_IMPL_OPENGL_ES2)
	#include <GLES2/gl2.h>
	#endif
	#include <GLFW/glfw3.h>       // Will drag system OpenGL headers
#else
	#pragma comment(lib, "opengl32")
	#pragma comment(lib, "glew32")
	#pragma comment(lib, "glfw3")
	#pragma comment(lib, "soil2-debug")
	
	#include <iostream>
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
	//#include <glew-2.1.0/glu.h> // Not wrangled by glew, see https://stackoverflow.com/a/3933593 && https://stackoverflow.com/a/73303899
	#include <GL/GLU.h>           // Windows SDK, at "C:\Program Files\Microsoft SDKs\Windows\vX.XA\Include\gl", see https://stackoverflow.com/a/3933593
	#include "engine.h"

#endif

#ifndef _CONSOLE                  // Windows Subsystem selection - Include Windows symbols if linking against Windows subsystem as opposed to the console subsystem (wWinMain vs. main)
	#include <Windows.h>          // Console subsystem-linked programs are "console" programs and as such have a windows console with
								  // a conhost servicing that windows console (with an actual console window) by default. Windows subsystem-linked programs are "not-console" programs,
                                  // and as such, do not have a console allocated and serviced by default, and thus must use AllocConsole();
								  // Additionally, we let the linker pick which entrypoint to link against, (wWinMain vs. main), and thus don't need any extra logic.
								  // 
                                  // *TLDR: This is a debug vs. release feature. Release programs shouldn't have a pesky console window show alongside the application.
#endif

//#include "Log.h"