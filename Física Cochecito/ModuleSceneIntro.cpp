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
	recta1.size = { 20, 1, 300 };
	recta1.SetPos(0, 0, 0);
	recta = App->physics->AddBody(recta1, 0, 3.0f);
	

	curva1.color = Yellow;
	curva1.size = { 20, 1, 50 };
	curva1.SetRotation(-30, vec3(0, 1, 0));
	curva1.SetPos(-10, 0, 165);
	curva = App->physics->AddBody(curva1, 0, 0);

	curva1_1.color = Yellow;
	curva1_1.size = { 20, 1, 50 };
	curva1_1.SetRotation(-45, vec3(0, 1, 0));
	curva1_1.SetPos(-35, 0, 195);
	App->physics->AddBody(curva1_1, 0, 0);

	curva1_2.color = Yellow;
	curva1_2.size = { 20, 1, 50 };
	curva1_2.SetRotation(-60, vec3(0, 1, 0));
	curva1_2.SetPos(-72, 0, 224);
	App->physics->AddBody(curva1_2, 0, 0);

	curva1_3.color = Yellow;
	curva1_3.size = { 20, 1, 200 };
	curva1_3.SetRotation(-90, vec3(0, 1, 0));
	curva1_3.SetPos(-185, 0, 235);
	App->physics->AddBody(curva1_3, 0, 0);

	rampa.color = Yellow;
	rampa.size = { 50, 1, 20 };
	rampa.SetRotation(-30, vec3(0, 0, 1));
	rampa.SetPos(-285, 0, 235);
	App->physics->AddBody(rampa, 0, 0);

	rectaAfterRamp.color = Yellow;
	rectaAfterRamp.size = { 150, 1, 40 };
	rectaAfterRamp.SetPos(-500, 25, 235);
	App->physics->AddBody(rectaAfterRamp, 0, 0);

	curva2.color = Yellow;
	curva2.size = { 40, 1, 75 };
	curva2.SetRotation(-75, vec3(0, 1, 0));
	curva2.SetPos(-595, 25, 240);
	curva = App->physics->AddBody(curva2, 0, 0);

	curva2_1.color = Yellow;
	curva2_1.size = { 40, 1, 75 };
	curva2_1.SetRotation(-60, vec3(0, 1, 0));
	curva2_1.SetPos(-658, 25, 268);
	App->physics->AddBody(curva2_1, 0, 0);

	curva2_2.color = Yellow;
	curva2_2.size = { 40, 1, 75 };
	curva2_2.SetRotation(-30, vec3(0, 1, 0));
	curva2_2.SetPos(-700, 25, 310);
	App->physics->AddBody(curva2_2, 0, 0);

	curva2_3.color = Yellow;
	curva2_3.size = { 40, 1, 175 };
	curva2_3.SetPos(-720, 25, 410);
	App->physics->AddBody(curva2_3, 0, 0);
	

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
	curva1_1.Render();
	curva1_2.Render();
	curva1_3.Render();
	rampa.Render();
	rectaAfterRamp.Render();
	curva2.Render();
	curva2_1.Render();
	curva2_2.Render();
	curva2_3.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}

