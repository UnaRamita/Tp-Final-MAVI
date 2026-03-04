#pragma once
#include <iostream>
#include "raylib.h"	
	
using namespace std;
class game
{
public:
	game();
	~game();

	void Update();
private:
	//esto no se si lo voy a usar
	float musicVolume;
	float fxVolume;
	//
	
	void Inits()
	void Load();
	void Inputs();
};

game::game()
{
}

game::~game()
{
}