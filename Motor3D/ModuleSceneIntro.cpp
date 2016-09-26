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
	uint my_id = 0;

	//vector<Vector3> vertices;

	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 2.f, 0.f);
	glVertex3f(0.f, 0.f, 2.f);

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

	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_VERTEX_ARRAY, my_id);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

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
	//glDisableClientState(GL_VERTEX_ARRAY);

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::CreateCubePrimitive()
{
}


