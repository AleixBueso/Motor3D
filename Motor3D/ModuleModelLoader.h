#pragma once
#include "Globals.h"
#include "Module.h"

class ModuleModelLoader : public Module
{
public:

	ModuleModelLoader(Application* app, bool start_enabled = true);
	~ModuleModelLoader();

	bool Start();
	bool CleanUp();

	update_status Update(float dt);

	bool LoadModel(const char* full_path);

};

struct MyMesh
{
	uint id_vertices = 0; // id in VRAM
	uint num_indices = 0;
	uint* indices = nullptr;
	uint id_indices = 0; // id in VRAM
	uint num_vertices = 0;
	float* vertices = nullptr;
};