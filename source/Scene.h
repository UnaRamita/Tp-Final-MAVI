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

	bool gameStart;
	bool options;
	bool pause;
	bool exitGame;

	Vector2 mousePos;

	Texture2D backgroundTexture;
	Texture2D buttonTexture;
	Texture2D mapTexture1;
	Texture2D mapTexture2;				
	Texture2D mapTexture3;
	Texture2D mapTexture4;

	Rectangle playButton;
	Rectangle optionButton;
	Rectangle exitButton;

	void Load();
	void Inputs();
};

