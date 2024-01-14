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
	recta1.SetPos(0, 10, 0);
	recta = App->physics->AddBody(recta1, 0, 3.0f);
	

	curva1.color = Yellow;
	curva1.size = { 20, 1, 50 };
	curva1.SetRotation(-30, vec3(0, 1, 0));
	curva1.SetPos(-10, 10, 165);
	curva = App->physics->AddBody(curva1, 0, 0);

	curva1_1.color = Yellow;
	curva1_1.size = { 20, 1, 50 };
	curva1_1.SetRotation(-45, vec3(0, 1, 0));
	curva1_1.SetPos(-35, 10, 195);
	App->physics->AddBody(curva1_1, 0, 0);

	curva1_2.color = Yellow;
	curva1_2.size = { 20, 1, 50 };
	curva1_2.SetRotation(-60, vec3(0, 1, 0));
	curva1_2.SetPos(-72, 10, 224);
	App->physics->AddBody(curva1_2, 0, 0);

	curva1_3.color = Yellow;
	curva1_3.size = { 20, 1, 200 };
	curva1_3.SetRotation(-90, vec3(0, 1, 0));
	curva1_3.SetPos(-185, 10, 235);
	App->physics->AddBody(curva1_3, 0, 0);

	rampa.color = Yellow;
	rampa.size = { 50, 1, 20 };
	rampa.SetRotation(-30, vec3(0, 0, 1));
	rampa.SetPos(-285, 10, 235);
	App->physics->AddBody(rampa, 0, 0);

	rectaAfterRamp.color = Yellow;
	rectaAfterRamp.size = { 150, 1, 40 };
	rectaAfterRamp.SetPos(-500, 35, 235);
	App->physics->AddBody(rectaAfterRamp, 0, 0);

	curva2.color = Yellow;
	curva2.size = { 40, 1, 75 };
	curva2.SetRotation(-75, vec3(0, 1, 0));
	curva2.SetPos(-595, 35, 240);
	App->physics->AddBody(curva2, 0, 0);

	curva2_1.color = Yellow;
	curva2_1.size = { 40, 1, 75 };
	curva2_1.SetRotation(-60, vec3(0, 1, 0));
	curva2_1.SetPos(-658, 35, 268);
	App->physics->AddBody(curva2_1, 0, 0);

	curva2_2.color = Yellow;
	curva2_2.size = { 40, 1, 75 };
	curva2_2.SetRotation(-30, vec3(0, 1, 0));
	curva2_2.SetPos(-700, 35, 310);
	App->physics->AddBody(curva2_2, 0, 0);

	curva2_3.color = Yellow;
	curva2_3.size = { 40, 1, 205 };
	curva2_3.SetPos(-720, 35, 425);
	App->physics->AddBody(curva2_3, 0, 0);

	curva3.color = Yellow;
	curva3.size = { 40, 1, 75 };
	curva3.SetRotation(30, vec3(0, 1, 0));
	curva3.SetPos(-705, 35, 540);
	App->physics->AddBody(curva3, 0, 0);

	curva3_1.color = Yellow;
	curva3_1.size = { 40, 1, 75 };
	curva3_1.SetRotation(45, vec3(0, 1, 0));
	curva3_1.SetPos(-665, 35, 590);
	App->physics->AddBody(curva3_1, 0, 0);

	curva3_2.color = Yellow;
	curva3_2.size = { 40, 1, 75 };
	curva3_2.SetRotation(60, vec3(0, 1, 0));
	curva3_2.SetPos(-615, 35, 630);
	App->physics->AddBody(curva3_2, 0, 0);

	curva3_3.color = Yellow;
	curva3_3.size = { 40, 1, 150 };
	curva3_3.SetRotation(90, vec3(0, 1, 0));
	curva3_3.SetPos(-525, 35, 648);
	App->physics->AddBody(curva3_3, 0, 0);
	
	rectaBeforeIce.color = Yellow;
	rectaBeforeIce.size = { 20, 1, 200 };
	rectaBeforeIce.SetRotation(90, vec3(0, 1, 0));
	rectaBeforeIce.SetPos(-300, 10, 648);
	App->physics->AddBody(rectaBeforeIce, 0, 0);

	Ice1.color = BlueClaro;
	Ice1.size = { 100, 1, 20 };
	Ice1.SetRotation(30, vec3(0, 1, 0));
	Ice1.SetPos(-162, 10, 625);
	App->physics->AddBody(Ice1, 0, 0);

	Ice2.color = BlueClaro;
	Ice2.size = { 100, 1, 20 };
	Ice2.SetRotation(60, vec3(0, 1, 0));
	Ice2.SetPos(-97, 10, 560);
	App->physics->AddBody(Ice2, 0, 0);

	rectaPitote.color = Yellow;
	rectaPitote.size = { 100, 1, 20 };
	rectaPitote.SetRotation(90, vec3(0, 1, 0));
	rectaPitote.SetPos(-72, 10, 472);
	App->physics->AddBody(rectaPitote, 0, 0);

	bouncePad.color = Red;
	bouncePad.size = { 20, 1, 20 };
	bouncePad.SetRotation(90, vec3(0, 1, 0));
	bouncePad.SetPos(-72, 10, 412);
	App->physics->AddBody(bouncePad, 0, 0);

	padSensor = App->physics->AddBody(Cube(20, 20, 20), 0);
	padSensor->collision_listeners.add(this);
	padSensor->SetPos(-72, 15, 412);
	padSensor->SetAsSensor(true);

	rectaPitote2.color = Yellow;
	rectaPitote2.size = { 200, 1, 20 };
	rectaPitote2.SetRotation(90, vec3(0, 1, 0));
	rectaPitote2.SetPos(-72, 20, 250);
	App->physics->AddBody(rectaPitote2, 0, 0);

	rectaPitote3.color = Yellow;
	rectaPitote3.size = { 200, 1, 20 };
	rectaPitote3.SetRotation(90, vec3(0, 1, 0));
	rectaPitote3.SetPos(-72, 20, 50);
	App->physics->AddBody(rectaPitote3, 0, 0);

	rectaPitote4.color = Yellow;
	rectaPitote4.size = { 200, 1, 20 };
	rectaPitote4.SetRotation(90, vec3(0, 1, 0));
	rectaPitote4.SetPos(-72, 20, -150);
	App->physics->AddBody(rectaPitote4, 0, 0);

	rectaPitote5.color = Yellow;
	rectaPitote5.size = { 140, 1, 20 };
	rectaPitote5.SetRotation(90, vec3(0, 1, 0));
	rectaPitote5.SetPos(-72, 20, -270);
	App->physics->AddBody(rectaPitote5, 0, 0);

	caminoLargo1.color = RedClaro;
	caminoLargo1.size = { 20, 1, 100 };
	caminoLargo1.SetRotation(30, vec3(0, 1, 0));
	caminoLargo1.SetPos(-98, 20, 50);
	App->physics->AddBody(caminoLargo1, 0, 0);

	caminoLargo2.color = RedClaro;
	caminoLargo2.size = { 20, 1, 100 };
	caminoLargo2.SetRotation(15, vec3(0, 1, 0));
	caminoLargo2.SetPos(-135, 20, -38);
	App->physics->AddBody(caminoLargo2, 0, 0);

	caminoLargo3.color = RedClaro;
	caminoLargo3.size = { 20, 1, 100 };
	caminoLargo3.SetPos(-148, 20, -133);
	App->physics->AddBody(caminoLargo3, 0, 0);

	caminoLargo4.color = RedClaro;
	caminoLargo4.size = { 20, 1, 100 };
	caminoLargo4.SetRotation(-15, vec3(0, 1, 0));
	caminoLargo4.SetPos(-135, 20, -228);
	App->physics->AddBody(caminoLargo4, 0, 0);

	caminoLargo5.color = RedClaro;
	caminoLargo5.size = { 20, 1, 100 };
	caminoLargo5.SetRotation(-30, vec3(0, 1, 0));
	caminoLargo5.SetPos(-98, 20, -318);
	App->physics->AddBody(caminoLargo5, 0, 0);

	caminoLargo6.color = RedClaro;
	caminoLargo6.size = { 30, 1, 80 };
	caminoLargo6.SetRotation(-90, vec3(0, 1, 0));
	caminoLargo6.SetPos(-35, 20, -350);
	App->physics->AddBody(caminoLargo6, 0, 0);

	rectaFinal1.color = Yellow;
	rectaFinal1.size = { 20, 1, 100 };
	rectaFinal1.SetPos(0, 20, -315);
	App->physics->AddBody(rectaFinal1, 0, 0);

	rampaFinal.color = Yellow;
	rampaFinal.size = { 20, 1, 50 };
	rampaFinal.SetRotation(195, vec3(1, 0, 0));
	rampaFinal.SetPos(0, 13, -242);
	App->physics->AddBody(rampaFinal, 0, 0);

	rectaFinal2.color = Yellow;
	rectaFinal2.size = { 20, 1, 100 };
	rectaFinal2.SetPos(0, 10, -200);
	App->physics->AddBody(rectaFinal2, 0, 0);

	deathField = App->physics->AddBody(Cube(2000, 2, 2000), 0);
	deathField->collision_listeners.add(this);
	deathField->SetPos(0, 0, 0);
	deathField->SetAsSensor(true);

	deathZone.color = Red;
	deathZone.size = { 2000, 1, 2000 };
	deathZone.SetPos(0, 0, 0);

	checkPoint_1 = App->physics->AddBody(Cube(5, 10, 20), 0);
	checkPoint_1->collision_listeners.add(this);
	checkPoint_1->SetPos(-105, 12, 235);
	checkPoint_1->SetAsSensor(true);

	checkPoint_2 = App->physics->AddBody(Cube(40, 10, 5), 0);
	checkPoint_2->collision_listeners.add(this);
	checkPoint_2->SetPos(-720, 40, 425);
	checkPoint_2->SetAsSensor(true);

	checkPoint_3 = App->physics->AddBody(Cube(25, 10, 5), 0);
	checkPoint_3->collision_listeners.add(this);
	checkPoint_3->SetPos(-72, 25, 250);
	checkPoint_3->SetAsSensor(true);

	checkPointMeta = App->physics->AddBody(Cube(20, 10, 5), 0);
	checkPointMeta->collision_listeners.add(this);
	checkPointMeta->SetPos(0, 15, 20);
	checkPointMeta->SetAsSensor(true);

	App->audio->PlayMusic("Assets/Audio/Music/MarioKart.wav");

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

	deathZone.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}

