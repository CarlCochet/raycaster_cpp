#pragma once

#include <vector>
#include "raylib.h"
#include "utils.h"

class Obstacle
{
private:
	Vector2 m_position;
	Vector2 m_size;

public:
	Obstacle();
	~Obstacle();
	void Render();
	std::vector<Line> GetLines();

};

