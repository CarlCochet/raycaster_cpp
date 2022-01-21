#pragma once

#include "raylib.h"
#include "utils.h"

class Player
{
private:
	Vector2 position;
	Vector2 forward;

public:
	Player();
	~Player();
	void Render();
	void Move(Direction direction);

};

