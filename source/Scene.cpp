#include "Scene.h"

scene::scene()
{
	sceneN = 1;
	fontSize = 40;//probar tamaños dsp con el meno ya hecho

	gameStart = false;
	options = false;
	pause = false;

	mousePos = GetMousePosition();

	backgroundTexture = LoadTexture("Assets/Sprites/Map/Ab_D.png");// es para poner algo despues cambiarlo // no se cual es el error aca dsp corrijo
	buttonTexture = LoadTexture("Assets/Sprites/Others/StoneButton.png");

	mapTexture1 = LoadTexture("Assets/Sprites/Map/Ab_D.png");
	mapTexture2 = LoadTexture("Assets/Sprites/Map/Ab_I.png");
	mapTexture3 = LoadTexture("Assets/Sprites/Map/Ar_D.png");
	mapTexture4 = LoadTexture("Assets/Sprites/Map/Ar_I.png");
	//creo que lo que me esta tirando error aca es hacer los calculos de los botones en el constructor, los voy a mover a inits
	playButton = {100,100,100,100 };
	optionButton = { 100,100,100,100 };
	exitButton = { 100,100,100,100 };
}
//aca solo inicializar entidades, pantalla y demas va en game
void scene::Inits() {
	playButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2,(float)GetScreenHeight() / 2 - buttonTexture.height, (float)buttonTexture.width, (float)buttonTexture.height };
	optionButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 100, (float)buttonTexture.width, (float)buttonTexture.height };
	exitButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 200, (float)buttonTexture.width, (float)buttonTexture.height };
}
void scene::Load() {
	Color tempColor = RAYWHITE;
	switch (sceneN)
	{
		//menu inicial
	case 1:
		//uno por boton
		Color tempColor1 = RAYWHITE;
		Color tempColor2 = RAYWHITE;
		Color tempColor3 = RAYWHITE;
		//fondo
		DrawTexture(backgroundTexture, 0, 0, RAYWHITE);
		//boton de play
		DrawTextureEx(buttonTexture, { playButton.x,playButton.y }, 0, 1, RAYWHITE);
		if (mousePos.x >= playButton.x && mousePos.y >= playButton.y && mousePos.x <= playButton.x + playButton.width && mousePos.y <= playButton.y + playButton.height) {
			tempColor1 = BLACK;
		}
		else {
			tempColor1 = RAYWHITE;
		}
		DrawText("Play", GetScreenWidth() /2 - buttonTexture.width / 2 +fontSize/2, playButton.y+playButton.height/2-fontSize/2,fontSize,tempColor1);//esto no se si lo centre bien, me enterare cuando lo vea

		break;
	case 2:

		break;
	default:
		sceneN = 1;
		break;
	}
}
void scene::Inputs() {
	mousePos = GetMousePosition();
	//menu
	if (sceneN = 1) {
		//playbutton act
		if (mousePos.x >= playButton.x && mousePos.y >= playButton.y && mousePos.x <= playButton.x + playButton.width && mousePos.y <= playButton.y + playButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			sceneN = 2;
		}
		//optionbutton act
		if (mousePos.x >= optionButton.x && mousePos.y >= optionButton.y && mousePos.x <= optionButton.x + optionButton.width && mousePos.y <= optionButton.y + optionButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			sceneN = 4;
		}
		//exitbutton act (todavia no se si va aca pero de ultima dsp lo cambio)
		if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

		}
	}
}
void scene::Update() {
	Inputs();
	Load();
}
scene::~scene()
{
}