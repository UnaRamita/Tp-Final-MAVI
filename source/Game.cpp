#include "Game.h"
game::game()
{
	fxVolume = 50;
	musicVolume = 50;
}

void game::Inits() {
	InitWindow(1920,1080,"Tp Final MAVI");
	SetTargetFPS(60);

	scene.Inits();
}
void game::Update(){
	scene.Update();
}
game::~game()
{