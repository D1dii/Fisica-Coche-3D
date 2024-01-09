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
	App->physics->AddBody(curva2, 0, 0);

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
	curva2_3.size = { 40, 1, 205 };
	curva2_3.SetPos(-720, 25, 425);
	App->physics->AddBody(curva2_3, 0, 0);

	curva3.color = Yellow;
	curva3.size = { 40, 1, 75 };
	curva3.SetRotation(30, vec3(0, 1, 0));
	curva3.SetPos(-705, 25, 540);
	App->physics->AddBody(curva3, 0, 0);

	curva3_1.color = Yellow;
	curva3_1.size = { 40, 1, 75 };
	curva3_1.SetRotation(45, vec3(0, 1, 0));
	curva3_1.SetPos(-665, 25, 590);
	App->physics->AddBody(curva3_1, 0, 0);

	curva3_2.color = Yellow;
	curva3_2.size = { 40, 1, 75 };
	curva3_2.SetRotation(60, vec3(0, 1, 0));
	curva3_2.SetPos(-615, 25, 630);
	App->physics->AddBody(curva3_2, 0, 0);

	curva3_3.color = Yellow;
	curva3_3.size = { 40, 1, 150 };
	curva3_3.SetRotation(90, vec3(0, 1, 0));
	curva3_3.SetPos(-525, 25, 648);
	App->physics->AddBody(curva3_3, 0, 0);
	
	rectaBeforeIce.color = Yellow;
	rectaBeforeIce.size = { 20, 1, 200 };
	rectaBeforeIce.SetRotation(90, vec3(0, 1, 0));
	rectaBeforeIce.SetPos(-300, 0, 648);
	App->physics->AddBody(rectaBeforeIce, 0, 0);

	Ice1.color = BlueClaro;
	Ice1.size = { 100, 1, 20 };
	Ice1.SetRotation(30, vec3(0, 1, 0));
	Ice1.SetPos(-162, 0, 625);
	App->physics->AddBody(Ice1, 0, 0);

	Ice2.color = BlueClaro;
	Ice2.size = { 100, 1, 20 };
	Ice2.SetRotation(60, vec3(0, 1, 0));
	Ice2.SetPos(-97, 0, 560);
	App->physics->AddBody(Ice2, 0, 0);

	rectaPitote.color = Yellow;
	rectaPitote.size = { 100, 1, 20 };
	rectaPitote.SetRotation(90, vec3(0, 1, 0));
	rectaPitote.SetPos(-72, 0, 472);
	App->physics->AddBody(rectaPitote, 0, 0);

	bouncePad.color = Red;
	bouncePad.size = { 20, 1, 20 };
	bouncePad.SetRotation(90, vec3(0, 1, 0));
	bouncePad.SetPos(-72, 0, 412);
	App->physics->AddBody(bouncePad, 0, 0);

	padSensor = App->physics->AddBody(Cube(20, 20, 20), 0);
	padSensor->collision_listeners.add(this);
	padSensor->SetPos(-72, 5, 412);
	padSensor->SetAsSensor(true);

	rectaPitote2.color = Yellow;
	rectaPitote2.size = { 200, 1, 20 };
	rectaPitote2.SetRotation(90, vec3(0, 1, 0));
	rectaPitote2.SetPos(-72, 10, 250);
	App->physics->AddBody(rectaPitote2, 0, 0);

	rectaPitote3.color = Yellow;
	rectaPitote3.size = { 200, 1, 20 };
	rectaPitote3.SetRotation(90, vec3(0, 1, 0));
	rectaPitote3.SetPos(-72, 10, 50);
	App->physics->AddBody(rectaPitote3, 0, 0);

	rectaPitote4.color = Yellow;
	rectaPitote4.size = { 200, 1, 20 };
	rectaPitote4.SetRotation(90, vec3(0, 1, 0));
	rectaPitote4.SetPos(-72, 10, -150);
	App->physics->AddBody(rectaPitote4, 0, 0);

	rectaPitote5.color = Yellow;
	rectaPitote5.size = { 140, 1, 20 };
	rectaPitote5.SetRotation(90, vec3(0, 1, 0));
	rectaPitote5.SetPos(-72, 10, -270);
	App->physics->AddBody(rectaPitote5, 0, 0);

	caminoLargo1.color = RedClaro;
	caminoLargo1.size = { 20, 1, 100 };
	caminoLargo1.SetRotation(30, vec3(0, 1, 0));
	caminoLargo1.SetPos(-98, 10, 50);
	App->physics->AddBody(caminoLargo1, 0, 0);

	caminoLargo2.color = RedClaro;
	caminoLargo2.size = { 20, 1, 100 };
	caminoLargo2.SetRotation(15, vec3(0, 1, 0));
	caminoLargo2.SetPos(-135, 10, -38);
	App->physics->AddBody(caminoLargo2, 0, 0);

	caminoLargo3.color = RedClaro;
	caminoLargo3.size = { 20, 1, 100 };
	caminoLargo3.SetPos(-148, 10, -133);
	App->physics->AddBody(caminoLargo3, 0, 0);

	caminoLargo4.color = RedClaro;
	caminoLargo4.size = { 20, 1, 100 };
	caminoLargo4.SetRotation(-15, vec3(0, 1, 0));
	caminoLargo4.SetPos(-135, 10, -228);
	App->physics->AddBody(caminoLargo4, 0, 0);

	caminoLargo5.color = RedClaro;
	caminoLargo5.size = { 20, 1, 100 };
	caminoLargo5.SetRotation(-30, vec3(0, 1, 0));
	caminoLargo5.SetPos(-98, 10, -318);
	App->physics->AddBody(caminoLargo5, 0, 0);

	caminoLargo6.color = RedClaro;
	caminoLargo6.size = { 30, 1, 80 };
	caminoLargo6.SetRotation(-90, vec3(0, 1, 0));
	caminoLargo6.SetPos(-35, 10, -350);
	App->physics->AddBody(caminoLargo6, 0, 0);

	rectaFinal1.color = Yellow;
	rectaFinal1.size = { 20, 1, 100 };
	rectaFinal1.SetPos(0, 10, -315);
	App->physics->AddBody(rectaFinal1, 0, 0);

	rampaFinal.color = Yellow;
	rampaFinal.size = { 20, 1, 50 };
	rampaFinal.SetRotation(195, vec3(1, 0, 0));
	rampaFinal.SetPos(0, 3, -242);
	App->physics->AddBody(rampaFinal, 0, 0);

	rectaFinal2.color = Yellow;
	rectaFinal2.size = { 20, 1, 100 };
	rectaFinal2.SetPos(0, 0, -200);
	App->physics->AddBody(rectaFinal2, 0, 0);

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

	/*recta1.Render();
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
	curva3.Render();
	curva3_1.Render();
	curva3_2.Render();
	curva3_3.Render();
	rectaBeforeIce.Render();
	Ice1.Render();
	Ice2.Render();
	rectaPitote.Render();
	bouncePad.Render();
	rectaPitote2.Render();
	rectaPitote3.Render();
	rectaPitote4.Render();
	rectaPitote5.Render();
	caminoLargo1.Render();
	caminoLargo2.Render();
	caminoLargo3.Render();
	caminoLargo4.Render();
	caminoLargo5.Render();
	caminoLargo6.Render();
	rectaFinal1.Render();
	rampaFinal.Render();
	rectaFinal2.Render();*/

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}

