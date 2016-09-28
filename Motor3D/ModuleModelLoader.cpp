#include "Globals.h"
#include "Application.h"
#include "ModuleModelLoader.h"

#include "Assimp/include/cimport.h"
#include "Assimp/include/scene.h"
#include "Assimp/include/postprocess.h"
#include "Assimp/include/cfileio.h"
#pragma comment (lib, "Assimp/libx86/assimp.lib")

ModuleModelLoader::ModuleModelLoader(Application* app, bool start_enabled) : Module(app, start_enabled)
{};

ModuleModelLoader::~ModuleModelLoader()
{
};

bool ModuleModelLoader::Start()
{
	LOG("Loading ModelLoader");
	bool ret = true;

	struct aiLogStream stream;
	stream = aiGetPredefinedLogStream(aiDefaultLogStream_DEBUGGER, nullptr);
	aiAttachLogStream(&stream);

	return ret;
};

bool ModuleModelLoader::CleanUp()
{
	LOG("Unloading ModelLoader");

	aiDetachAllLogStreams();

	return true;
};

update_status ModuleModelLoader::Update(float dt)
{

	return UPDATE_CONTINUE;
};

bool ModuleModelLoader::LoadModel(const char* full_path)
{
	bool ret = true;

	const aiScene* scene = aiImportFile(full_path, aiProcessPreset_TargetRealtime_MaxQuality);	if (scene != nullptr && scene->HasMeshes())
	{
		// Use scene->mNumMeshes to iterate on scene->mMeshes array
		for (uint i = 0; i >= scene->mNumMeshes; i++)
		{
			MyMesh m;
			m.num_vertices = scene->mMeshes[i]->mNumVertices;
			m.vertices = new float[m.num_vertices * 3];
			memcpy(m.vertices, scene->mMeshes[i]->mVertices, sizeof(float) * m.num_vertices * 3);
			LOG("New mesh with %d vertices", m.num_vertices);

			if (scene->mMeshes[i]->HasFaces())
			{
				m.num_indices = scene->mMeshes[i]->mNumFaces * 3;
				m.indices = new uint[m.num_indices]; // assume each face is a triangle
				for (uint i = 0; i < scene->mMeshes[i]->mNumFaces; ++i)
				{
					if (scene->mMeshes[i]->mFaces[i].mNumIndices != 3)
					{
						LOG("WARNING, geometry face with != 3 indices!");
					}

					else
						memcpy(&m.indices[i * 3], scene->mMeshes[i]->mFaces[i].mIndices, 3 * sizeof(uint));
						
				}
			}
		}

		aiReleaseImport(scene);
	}
	else
	{
		LOG("Error loading scene %s", full_path);
		ret = false;
	}

	return ret;
}