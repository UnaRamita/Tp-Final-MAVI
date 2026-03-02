#pragma once
#include <iostream>
#include "raylib.h"	
#include "Player.h"
#include "Enemy.h"
	
using namespace std;
class game
{
public:
	game();
	~game();

private:
	float musicVolume;
	float fxVolume;

	
	void Load();
	void Inputs();
};

game::game()
{
}

game::~game()
{
}