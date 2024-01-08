#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	recta1.color = Yellow;
	recta1.size = { 20, 1, 200 };
	recta1.SetPos(0, 0, 0);
	recta = App->physics->AddBody(recta1, 0, 3.0f);

	curva1.color = BlueClaro;
	curva1.size = { 20, 1, 100 };
	curva1.SetRotation(90, vec3(0, 1, 0));
	curva1.SetPos(-40, 0, 110);
	curva = App->physics->AddBody(curva1, 0, 0);
	

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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	recta1.Render();
	curva1.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body1 == recta && body2 == App->player->vehicle)
	{
		App->player->friction = 1.0f;
	}
	else if (body2 == curva && body2 == App->player->vehicle)
	{
		App->player->friction = 0;
	}
}

