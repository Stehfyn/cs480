#pragma once
#include "Application.h"
#include "ImGuiLog.h"
class ImGuiApplication : private Application
{
public:
	ImGuiApplication(const char* app_name, unsigned int w, unsigned int h);
	~ImGuiApplication();

	void Run();
	void Initialize() = 0;
	void Update() = 0;
private:
	GLFWwindow* m_Window;
};
