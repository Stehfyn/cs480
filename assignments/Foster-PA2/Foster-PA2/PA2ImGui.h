#include "ImGuiApplication.h"
#include "engine.h"
class PA2ImGui : public ImGuiApplication
{
public:
	PA2ImGui(const char* app_name, unsigned int w, unsigned int h) : ImGuiApplication(app_name, w, h) { m_engine = new Engine("urmmom", 100, 100); }
	~PA2ImGui() {}

	void Initialize()
	{
		m_engine->Initialize();
	}
	void Update()
	{
		unsigned int f_tex = 0;
		// do dockspace
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		//do render window
		ImGui::Begin("Render Window");
		//m_engine->Run();
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImVec2 avail = ImGui::GetContentRegionAvail();
		ImDrawList* drawList = ImGui::GetWindowDrawList();
		drawList->AddImage((void*)0,
			pos,
			ImVec2(pos.x + avail.x, pos.y + avail.y),
			ImVec2(0, 1),
			ImVec2(1, 0));
		ImGui::End();
		// do Vertex window

		ImGui::Begin("Object Window");
		ImGui::End();
        //do log window
		ImGuiLog::GetCoreLogger()->Draw("Log");
	}

private:
	void DoObjectWindow();
	Engine* m_engine;
};