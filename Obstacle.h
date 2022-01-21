#pragma once

#include <vector>
#include "raylib.h"
#include "utils.h"

class Obstacle
{
private:
	Vector2 position;
	Vector2 size;

public:
	Obstacle();
	~Obstacle();
	void Render();
	std::vector<Line> GetLines();

};

