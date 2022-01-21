#pragma once

#include "raylib.h"
#include "utils.h"

class Player
{
private:
	Vector2 m_position;
	Vector2 m_forward;

public:
	Player();
	~Player();
	void Render();
	void Move(Direction direction);

};

