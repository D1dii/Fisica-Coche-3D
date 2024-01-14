#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	Cube recta1;
	
	Cube curva1;
	Cube curva1_1;
	Cube curva1_2;
	Cube curva1_3;
	Cube rampa;
	Cube rectaAfterRamp;
	Cube curva2;
	Cube curva2_1;
	Cube curva2_2;
	Cube curva2_3;
	Cube curva3;
	Cube curva3_1;
	Cube curva3_2;
	Cube curva3_3;
	Cube rectaBeforeIce;
	Cube Ice1;
	Cube Ice2;
	Cube rectaPitote;
	Cube bouncePad;
	Cube rectaPitote2;
	Cube rectaPitote3;
	Cube rectaPitote4;
	Cube rectaPitote5;
	Cube caminoLargo1;
	Cube caminoLargo2;
	Cube caminoLargo3;
	Cube caminoLargo4;
	Cube caminoLargo5;
	Cube caminoLargo6;
	Cube rectaFinal1;
	Cube rampaFinal;
	Cube rectaFinal2;
	Cube deathZone;

	Cylinder BasePitote;
	Cube Pitote;

	Cylinder checkPointCyl1_1;
	Cylinder checkPointCyl1_2;
	Cylinder checkPointCyl2_1;
	Cylinder checkPointCyl2_2;
	Cylinder checkPointCyl3_1;
	Cylinder checkPointCyl3_2;
	Cylinder Meta1;
	Cylinder Meta2;


	PhysBody3D* recta;
	PhysBody3D* curva;
	PhysBody3D* padSensor;
	PhysBody3D* deathField;
	PhysBody3D* checkPoint_1;
	PhysBody3D* checkPoint_2;
	PhysBody3D* checkPoint_3;
	PhysBody3D* checkPointMeta;
	PhysBody3D* BaseGirar;
	PhysBody3D* pitoteGirar;

};
