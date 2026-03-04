#include "Scene.h"

scene::scene()
{
	gameStart = false;
	options = false;
	pause = false;

	resolution = { 1920, 1080 };

	backgroundTexture = LoadTexture("Assets\Map\Ab D.png");// es para poner algo despues cambiarlo
	buttonTexture = LoadTexture("Assets\Others\button"); //esta ruta por ahora no existe dsp la creo

	mapTexture1 = LoadTexture("Assets\Map\Ab D.png");
	mapTexture2 = LoadTexture("Assets\Map\Ab I.png");
	mapTexture3 = LoadTexture("Assets\Map\Ar D.png");
	mapTexture4 = LoadTexture("Assets\Map\Ar I.png");

	playButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2,(float)GetScreenHeight() / 2 - buttonTexture.height, (float)buttonTexture.width, (float)buttonTexture.height };
	optionButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 100, (float)buttonTexture.width, (float)buttonTexture.height };
	exitButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 200, (float)buttonTexture.width, (float)buttonTexture.height };
}
//aca solo inicializar entidades, pantalla y demas va en game
void scene::Inits() {

}
void scene::Load() {
	
}
void scene::Inputs() {

}
void scene::Update(int scene) {

}
scene::~scene()
{
}