#pragma once

#include <vector>
#include "raylib.h"
#include "Obstacle.h"

class Ray
{
private:
	Vector2 m_start;
	Vector2 m_end;
	Vector2 m_direction;
	float m_length;

public:
	Ray();
	~Ray();
	void Render();
	void Update(Vector2 playerPos, Vector2 playerDir);
	void ComputeCollision(std::vector<Obstacle> obstacles);

};

