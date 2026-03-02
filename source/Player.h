#pragma once
#include "Hud.h"

class player
{
public:
	player();
	~player();
    void update();
private:
	float speed;
	float scale;
	float rotation;

	Vector4 mapLimits;
	Vector2 Pos;
	Vector2 InitPos;
	Vector2 Vel;
	Vector2 HitBox;
};

player::player()
{
}

player::~player()
{
}
