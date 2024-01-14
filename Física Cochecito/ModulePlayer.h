#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 2000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:

	PhysVehicle3D* vehicle;
	vec3 carPos;
	vec3 savePos;
	float turn;
	float acceleration;
	float brake;
	float friction = 1.0f;
	bool isCheck1 = false;
	bool isCheck2 = false;
	bool isCheck3 = false;
	uint WinFx;
	uint DeathFx;
	uint CheckpointFx;
	bool isFrictionActive = true;
	bool debug = false;
};