#include "Scene.h"

scene::scene()
{
	sceneN = 1;
	fontSize = 40;//probar tamaños dsp con el meno ya hecho

	musicVolume = 100;
	fxVolume = 100;

	gameStart = false;
	options = false;
	pause = false;
	exitGame = false;

	mousePos = GetMousePosition();
	//a todo esto le pongo un valor y despues lo inicializo en inits para que se carge una vez creada la ventana
	backgroundTexture = { 0 };
	buttonTexture = { 0 };

	mapTexture1 = { 0 };
	mapTexture2 = { 0 };
	mapTexture3 = { 0 };
	mapTexture4 = { 0 };
    
	playButton = {100,100,100,100 };
	optionButton = { 100,100,100,100 };
	exitButton = { 100,100,100,100 };

	menuMusic = { 0 };
	gameMusic = { 0 };
}
//aca solo inicializar entidades, pantalla y demas va en game
void scene::Inits() {
	backgroundTexture = LoadTexture("Assets/Sprites/Map/Ab_D.png");// es para poner algo despues cambiarlo // no se cual es el error aca dsp corrijo
	buttonTexture = LoadTexture("Assets/Sprites/Others/StoneButton.png");

	mapTexture1 = LoadTexture("Assets/Sprites/Map/Ab_D.png");
	mapTexture2 = LoadTexture("Assets/Sprites/Map/Ab_I.png");
	mapTexture3 = LoadTexture("Assets/Sprites/Map/Ar_D.png");
	mapTexture4 = LoadTexture("Assets/Sprites/Map/Ar_I.png");

	playButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2,(float)GetScreenHeight() / 2 - buttonTexture.height, (float)buttonTexture.width, (float)buttonTexture.height };
	optionButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 100, (float)buttonTexture.width, (float)buttonTexture.height };
	exitButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 200, (float)buttonTexture.width, (float)buttonTexture.height };

	menuMusic = LoadMusicStream("Assets/Music/menu.mp3");
	gameMusic = LoadMusicStream("Assets/Music/game.mp3");
	PlayMusicStream(menuMusic);

}	
void scene::Load() {
	switch (sceneN)
	{
		//menu inicial
	case 1:
		//color del texto del boton
		Color tempColor1 = RAYWHITE;
		//musica
		UpdateMusicStream(menuMusic);
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
		//boton de options 
		DrawTextureEx(buttonTexture, { optionButton.x,optionButton.y }, 0, 1, RAYWHITE);
		if (mousePos.x >= optionButton.x && mousePos.y >= optionButton.y && mousePos.x <= optionButton.x + optionButton.width && mousePos.y <= optionButton.y + optionButton.height) {
			tempColor1 = BLACK;
		}
		else {
			tempColor1 = RAYWHITE;
		}
		DrawText("Options", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, optionButton.y + optionButton.height / 2 - fontSize / 2, fontSize, tempColor1);//esto no se si lo centre bien x2
		//boton de exit
		DrawTextureEx(buttonTexture, { exitButton.x,exitButton.y }, 0, 1, RAYWHITE);
		if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height) {
			tempColor1 = BLACK;
		}
		else {
			tempColor1 = RAYWHITE;
		}
		DrawText("Exit", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, exitButton.y + exitButton.height / 2 - fontSize / 2, fontSize, tempColor1);//esto no se si lo centre bien, me enterare cuand
		break;
	case 2:
		UpdateMusicStream(gameMusic);
		break;
	case 4:
		Color tempColor1 = RAYWHITE;
		//musica
		UpdateMusicStream(menuMusic);
		//fondo
		DrawTexture(backgroundTexture, 0, 0, RAYWHITE);
		//musicvolume 
		DrawTextureEx(buttonTexture, { playButton.x,playButton.y }, 0, 1, RAYWHITE);
		DrawText(to_string(musicVolume).c_str(), GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, playButton.y + playButton.height / 2 - fontSize / 2, fontSize, tempColor1);
		//fxvolume
		DrawTextureEx(buttonTexture, { optionButton.x,optionButton.y }, 0, 1, RAYWHITE);
		DrawText(to_string(musicVolume).c_str(), GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, optionButton.y + optionButton.height / 2 - fontSize / 2, fontSize, tempColor1);//esto no se si lo centre bien x2
		// boton de volver atras (es el mismo que el de exit peeero le cambie el texto)
		DrawTextureEx(buttonTexture, { exitButton.x,exitButton.y }, 0, 1, RAYWHITE);
		if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height) {
			tempColor1 = BLACK;
		}
		else {
			tempColor1 = RAYWHITE;
		}
		DrawText("Back", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, exitButton.y + exitButton.height / 2 - fontSize / 2, fontSize, tempColor1);//esto no se si lo centre bien, me enterare cuand

		break;
	default:
		sceneN = 1;
		break;
	}
}
void scene::Inputs() {
	mousePos = GetMousePosition();
	//menu
	if (sceneN == 1) {
		//playbutton act
		if (mousePos.x >= playButton.x && mousePos.y >= playButton.y && mousePos.x <= playButton.x + playButton.width && mousePos.y <= playButton.y + playButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			sceneN = 2;
			StopMusicStream(menuMusic);
			PlayMusicStream(gameMusic);

		}
		//optionbutton act
		if (mousePos.x >= optionButton.x && mousePos.y >= optionButton.y && mousePos.x <= optionButton.x + optionButton.width && mousePos.y <= optionButton.y + optionButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			sceneN = 4;
		}
		//exitbutton act (todavia no se si va aca pero de ultima dsp lo cambio)
		if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			exitGame = true;
		}
	}
	//options
	if (sceneN == 2) {

		//botton de ir hacia atras
		if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			sceneN = 1;
		}
	}
}
bool scene::ShouldExit()
{
	return exitGame;
}
void scene::Update() {
	Inputs();
	Load();
}
scene::~scene()
{
}