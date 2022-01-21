#pragma once

#include <vector>
#include "raylib.h"
#include "Obstacle.h"

class Ray
{
private:
	Vector2 start;
	Vector2 end;
	Vector2 direction;
	float length;

public:
	Ray();
	~Ray();
	void Render();
	void Update(Vector2 playerPos, Vector2 playerDir);
	void ComputeCollision(std::vector<Obstacle> obstacles);

};

