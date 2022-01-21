#pragma once

#include <vector>
#include "raylib.h"
#include "Obstacle.h"
#include "Player.h"
#include "Ray.h"

class Game
{
private:
	Player m_player;
	std::vector<Obstacle> m_obstacles;
	std::vector<Ray> m_rays;

public:
	Game();
	~Game();
	void ProcessInputs();
	void Render();
};

