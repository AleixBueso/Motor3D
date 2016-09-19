#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"
#include "Imgui\imgui.h"

ModuleEditor::ModuleEditor(Application* app, bool start_enabled) : Module(app, start_enabled)
{};

ModuleEditor::~ModuleEditor()
{};

bool ModuleEditor::Start()
{
	LOG("Loading Editor");
	bool ret = true;

	ShowTestWindow = false;

	return ret;
};

bool ModuleEditor::CleanUp()
{
	LOG("Unloading Editor");

	return true;
};

update_status ModuleEditor::Update(float dt) 
{
	//Create the menu bar
	if (ImGui::BeginMainMenuBar())
	{
		/*if (ImGui::MenuItem("Help"))
		{
			if(ImGui::MenuItem("Documentation"))

				
			if (ImGui::MenuItem("Download Latest"))


			if (ImGui::MenuItem("Report a Bug"))


			if (ImGui::MenuItem("About"))

		}*/

		if (ImGui::BeginMenu("View"))
		{
			if (ImGui::MenuItem("Test Window"))
				ShowTestWindow = !ShowTestWindow;

			ImGui::EndMenu();
		}

		if (ImGui::MenuItem("Quit"))
			return UPDATE_STOP;

		ImGui::EndMainMenuBar();
	}
	
	if(ShowTestWindow)
		ImGui::ShowTestWindow();

	return UPDATE_CONTINUE;
};