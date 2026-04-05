#pragma once
#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;
class scene
{
public:
	scene();
	~scene();

	bool ShouldExit();

	
	void Inits();
	void Update();
private:
	int sceneN;
	int fontSize;

	int musicVolume;
	int fxVolume;

	bool gameStart;
	bool options;
	bool pause;
	bool exitGame;
	bool canClick;

	Vector2 mousePos;

	Texture2D backgroundTexture;

	Texture2D buttonTexture;
	Texture2D buttonLitRightTexture1;
	Texture2D buttonLitRightTexture2;
	Texture2D buttonLitLeftTexture1;
	Texture2D buttonLitLeftTexture2;

	Texture2D mapTexture1;
	Texture2D mapTexture2;				
	Texture2D mapTexture3;
	Texture2D mapTexture4;

	Rectangle playButton;
	Rectangle optionButton;
	Rectangle exitButton;
	Rectangle volumeButton1;
	Rectangle volumeButton2;

	Music menuMusic;
	Music gameMusic;

	void Menu();
	void Options();
	void Game();
	void SetVolume();

	void Load();
	void Inputs();
};

