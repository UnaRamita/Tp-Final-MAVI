#pragma once
#include <iostream>
#include "raylib.h"	
#include "Scene.h"
using namespace std;
class game
{
public:
	game();
	~game();

	void Inits();
	void Run();
	
private:
	//esto no se si lo voy a usar aca
	float musicVolume;
	float fxVolume;
	//
	void Update();
	void Inputs();

	scene scene;
};
