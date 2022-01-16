#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 20.0f * DEGTORAD
#define BRAKE_POWER 200.0f

enum PLAYER_STATE
{
	PREPARE,
	READY,
	STEADY,
	GO,
	FINISH
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;

	bool  following_camera;
	PLAYER_STATE state;

};