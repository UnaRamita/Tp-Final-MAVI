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
	canClick = true;

	mousePos = GetMousePosition();
	//a todo esto le pongo un valor y despues lo inicializo en inits para que se carge una vez creada la ventana
	backgroundTexture = { 0 };

	buttonTexture = { 0 };
	buttonLitRightTexture1 = { 0 };
	buttonLitRightTexture2 = { 0 };
	buttonLitLeftTexture1 = { 0 };
	buttonLitLeftTexture2 = { 0 };


	mapTexture1 = { 0 };
	mapTexture2 = { 0 };
	mapTexture3 = { 0 };
	mapTexture4 = { 0 };
    
	playButton = {100,100,100,100 };
	optionButton = { 100,100,100,100 };
	exitButton = { 100,100,100,100 };
	volumeButton1 = { 100,100,100,100 };
	volumeButton2 = { 100,100,100,100 };

	menuMusic = { 0 };
	gameMusic = { 0 };
}
//aca solo inicializar entidades, pantalla y demas va en game
void scene::Inits() {
	backgroundTexture = LoadTexture("Assets/Sprites/Map/Ab_D.png");// es para poner algo despues cambiarlo // no se cual es el error aca dsp corrijo
	buttonTexture = LoadTexture("Assets/Sprites/Others/StoneButton.png");
	buttonLitRightTexture1 = LoadTexture("Assets/Sprites/Others/StoneButtonLRight.png");
	buttonLitRightTexture2 = LoadTexture("Assets/Sprites/Others/StoneButtonLRightW.png");
	buttonLitLeftTexture1 = LoadTexture("Assets/Sprites/Others/StoneButtonLLeft.png");
	buttonLitLeftTexture2 = LoadTexture("Assets/Sprites/Others/StoneButtonLLeftW.png");

	mapTexture1 = LoadTexture("Assets/Sprites/Map/Ab_D.png");
	mapTexture2 = LoadTexture("Assets/Sprites/Map/Ab_I.png");
	mapTexture3 = LoadTexture("Assets/Sprites/Map/Ar_D.png");
	mapTexture4 = LoadTexture("Assets/Sprites/Map/Ar_I.png");

	playButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2,(float)GetScreenHeight() / 2 - buttonTexture.height, (float)buttonTexture.width, (float)buttonTexture.height };
	optionButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 100, (float)buttonTexture.width, (float)buttonTexture.height };
	exitButton = { (float)GetScreenWidth() / 2 - buttonTexture.width / 2, (float)GetScreenHeight() / 2 - buttonTexture.height + 200, (float)buttonTexture.width, (float)buttonTexture.height };
	volumeButton1 = { (float)playButton.x - buttonLitLeftTexture1.width - 50,playButton.y,(float)buttonLitLeftTexture1.width,(float)buttonLitLeftTexture1.height };
	volumeButton2 = { (float)playButton.x + playButton.width + 50,playButton.y,(float)buttonLitLeftTexture1.width,(float)buttonLitLeftTexture1.height };

	menuMusic = LoadMusicStream("Assets/Music/menu.mp3");
	gameMusic = LoadMusicStream("Assets/Music/game.mp3");
	SetMusicVolume(menuMusic, musicVolume / 100.0);
	PlayMusicStream(menuMusic);

}	
void scene::Load() {
	switch (sceneN)
	{
		
	case 1:
		Menu();
		break;
	case 2:
		Game();
		break;
		
	case 4:
		Options();
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
		if (mousePos.x >= playButton.x && mousePos.y >= playButton.y && mousePos.x <= playButton.x + playButton.width && mousePos.y <= playButton.y + playButton.height && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			sceneN = 2;
			StopMusicStream(menuMusic);
			PlayMusicStream(gameMusic);

		}
		//optionbutton act
		if (mousePos.x >= optionButton.x && mousePos.y >= optionButton.y && mousePos.x <= optionButton.x + optionButton.width && mousePos.y <= optionButton.y + optionButton.height && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
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
	if (sceneN == 4) {
		//botones de volumen general
		//bajar
		if (canClick && mousePos.x >= volumeButton1.x && mousePos.y >= volumeButton1.y && mousePos.x <= volumeButton1.x + volumeButton1.width && mousePos.y <= volumeButton1.y + volumeButton1.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			musicVolume -= 5;
			SetVolume();
			canClick = false;
			//printf("music -5\n"); //debug por que sube y baja de a 10
			
		}
		//subir
		if (canClick&&mousePos.x >= volumeButton2.x && mousePos.y >= volumeButton2.y && mousePos.x <= volumeButton2.x + volumeButton2.width && mousePos.y <= volumeButton2.y + volumeButton2.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			musicVolume += 5;
			SetVolume();
			canClick = false;
		}
		//botonos de volumen fx
		//bajar
		if (canClick&&mousePos.x >= volumeButton1.x && mousePos.y >= volumeButton1.y + 100 && mousePos.x <= volumeButton1.x + volumeButton1.width && mousePos.y <= volumeButton1.y + 100 + volumeButton1.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			fxVolume -= 5;
			SetVolume();
			canClick = false;
		}
		//subir
		if (canClick&&mousePos.x >= volumeButton2.x && mousePos.y >= volumeButton2.y + 100 && mousePos.x <= volumeButton2.x + volumeButton2.width && mousePos.y <= volumeButton2.y + 100 + volumeButton2.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			fxVolume += 5;
			SetVolume();
			canClick = false;
		}

		//botton de ir hacia atras
		if (canClick&&mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			canClick = false;
			sceneN = 1;
		}
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		canClick = true;
	}
}
bool scene::ShouldExit()
{
	return exitGame;
}
void scene::Menu() {
	//menu inicial
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
	DrawText("Play", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, playButton.y + playButton.height / 2 - fontSize / 2, fontSize, tempColor1);
	//boton de options 
	DrawTextureEx(buttonTexture, { optionButton.x,optionButton.y }, 0, 1, RAYWHITE);
	if (mousePos.x >= optionButton.x && mousePos.y >= optionButton.y && mousePos.x <= optionButton.x + optionButton.width && mousePos.y <= optionButton.y + optionButton.height) {
		tempColor1 = BLACK;
	}
	else {
		tempColor1 = RAYWHITE;
	}
	DrawText("Options", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, optionButton.y + optionButton.height / 2 - fontSize / 2, fontSize, tempColor1);
	//boton de exit
	DrawTextureEx(buttonTexture, { exitButton.x,exitButton.y }, 0, 1, RAYWHITE);
	if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height) {
		tempColor1 = BLACK;
	}
	else {
		tempColor1 = RAYWHITE;
	}
	DrawText("Exit", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, exitButton.y + exitButton.height / 2 - fontSize / 2, fontSize, tempColor1);
}
void scene::Game() {
	//Game
	UpdateMusicStream(gameMusic);
}
void scene::Options() {
	//options
	Color tempColor2 = RAYWHITE;
	//musica
	UpdateMusicStream(menuMusic);
	//fondo
	DrawTexture(backgroundTexture, 0, 0, RAYWHITE);
	//musicvolume 
	DrawTextureEx(buttonTexture, { playButton.x,playButton.y }, 0, 1, RAYWHITE);
	DrawText(to_string(musicVolume).c_str(), GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, playButton.y + playButton.height / 2 - fontSize / 2, fontSize, tempColor2);
	DrawTextureEx(buttonLitLeftTexture1, { volumeButton1.x,volumeButton1.y }, 0, 1, RAYWHITE);
	DrawTextureEx(buttonLitRightTexture1, { volumeButton2.x,volumeButton2.y }, 0, 1, RAYWHITE);
	//fxvolume
	DrawTextureEx(buttonTexture, { optionButton.x,optionButton.y }, 0, 1, RAYWHITE);
	DrawText(to_string(fxVolume).c_str(), GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, optionButton.y + optionButton.height / 2 - fontSize / 2, fontSize, tempColor2);//esto no se si lo centre bien x2
	DrawTextureEx(buttonLitLeftTexture1, { volumeButton1.x,volumeButton1.y +100 }, 0, 1, RAYWHITE);
	DrawTextureEx(buttonLitRightTexture1, { volumeButton2.x,volumeButton2.y +100 }, 0, 1, RAYWHITE);
	// boton de volver atras (es el mismo que el de exit peeero le cambie el texto)
	DrawTextureEx(buttonTexture, { exitButton.x,exitButton.y }, 0, 1, RAYWHITE);
	if (mousePos.x >= exitButton.x && mousePos.y >= exitButton.y && mousePos.x <= exitButton.x + exitButton.width && mousePos.y <= exitButton.y + exitButton.height) {
		tempColor2 = BLACK;
	}
	else {
		tempColor2 = RAYWHITE;
	}
	DrawText("Back", GetScreenWidth() / 2 - buttonTexture.width / 2 + fontSize / 2, exitButton.y + exitButton.height / 2 - fontSize / 2, fontSize, tempColor2);
}
void scene::SetVolume(){
	if (musicVolume > 100)
	{
		musicVolume = 100;
	}
	if (fxVolume > 100) {
		fxVolume = 100;
	}
	if (musicVolume < 0)
	{
		musicVolume = 0;
	}
	if (fxVolume < 0) {
		fxVolume = 0;
	}

	float mVol = musicVolume / 100.0f;
	float fxVol = fxVolume / 100.0f;
			

	SetMusicVolume(menuMusic, mVol);
	SetMusicVolume(gameMusic, mVol);

	//aca despues tendria que setear el volumen de todos los sonidos que vaya sumando de los enemigos y demas
	//SetSoundVolume();
}
void scene::Update() {
	Inputs();
	Load();
}
scene::~scene()
{
}