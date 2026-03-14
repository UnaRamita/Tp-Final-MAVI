#include "Game.h"
game::game()
{
}

void game::Inits() {
	InitWindow(1920,1080,"Tp Final MAVI");
	SetTargetFPS(60);
	InitAudioDevice();

	scene.Inits();
}
void game::Update(){
	scene.Update();
}
bool game::Run() {
	ClearBackground(BLACK);
	Update();
	if (scene.ShouldExit())
	{
		return false;
	}
	else {
		return true;
	}
}
game::~game()
{
	CloseAudioDevice();
	CloseWindow();
}