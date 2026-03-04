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
	//la idea aca es que se pase un numero que va a representar la scena en si, si estamos en el menu, en el juego , en las opciones, en el nivel 2 y asi 
	void Update(int scene);
private:

	bool gameStart;
	bool options;
	bool pause;

	Vector2 resolution;

	Texture2D backgroundTexture;
	Texture2D buttonTexture;
	Texture2D mapTexture1;
	Texture2D mapTexture2;				
	Texture2D mapTexture3;
	Texture2D mapTexture4;

	Rectangle playButton;
	Rectangle optionButton;
	Rectangle exitButton;

	void Inits();
	void Load();
	void Inputs();
};

