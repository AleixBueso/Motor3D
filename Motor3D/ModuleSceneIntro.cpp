#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "SDL\include\SDL.h"

#include "Imgui\imgui.h"

#include "MathGeoLib\include\MathGeoLib.h"
#include "MathGeoLib\include\MathBuildConfig.h"

#include "Glew\include\glew.h"
#include "glut\glut.h"

#include "Random.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	
	vector<FixedPoint<float, sizeof(float)>>* vertices = vector<float4> cube_vertices;

	cube_vertices.push_back(FixedPoint<float, sizeof(float)>(0.f, 0.f, 0.f));
	cube_vertices.push_back(FixedPoint<float, sizeof(float)>(0.f, 2.f, 0.f));
	cube_vertices.push_back(FixedPoint<float, sizeof(float)>(0.f, 0.f, 2.f));

	glVertex3f(0.f, 2.f, 0.f);
	glVertex3f(0.f, 2.f, 2.f);
	glVertex3f(0.f, 0.f, 2.f);

	glVertex3f(0.f, 2.f, 0.f);
	glVertex3f(-2.f, 2.f, 2.f);
	glVertex3f(0.f, 2.f, 2.f);

	glVertex3f(0.f, 2.f, 0.f);
	glVertex3f(-2.f, 2.f, 0.f);
	glVertex3f(-2.f, 2.f, 2.f);

	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(-2.f, 2.f, 0.f);
	glVertex3f(0.f, 2.f, 0.f);

	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(-2.f, 0.f, 0.f);
	glVertex3f(-2.f, 2.f, 0.f);

	glVertex3f(-2.f, 0.f, 0.f);
	glVertex3f(-2.f, 2.f, 2.f);
	glVertex3f(-2.f, 2.f, 0.f);

	glVertex3f(-2.f, 0.f, 0.f);
	glVertex3f(-2.f, 0.f, 2.f);
	glVertex3f(-2.f, 2.f, 2.f);

	glVertex3f(-2.f, 0.f, 2.f);
	glVertex3f(0.f, 0.f, 2.f);
	glVertex3f(0.f, 2.f, 2.f);

	glVertex3f(-2.f, 0.f, 2.f);
	glVertex3f(0.f, 2.f, 2.f);
	glVertex3f(-2.f, 2.f, 2.f);

	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 2.f);
	glVertex3f(-2.f, 0.f, 0.f);

	glVertex3f(0.f, 0.f, 2.f);
	glVertex3f(-2.f, 0.f, 2.f);
	glVertex3f(-2.f, 0.f, 0.f);

	uint my_id = 0;
	glGenBuffers(1, (GLuint*)&(my_id));
	glBindBuffer(GL_ARRAY_BUFFER, my_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 12 * 3, vertices, GL_STATIC_DRAW);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	CreateCubePrimitive();

	glDrawArrays(GL_TRIANGLES, 0, 12 * 3 * 3);
	glDisableClientState(GL_VERTEX_ARRAY);

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::CreateCubePrimitive()
{
}


