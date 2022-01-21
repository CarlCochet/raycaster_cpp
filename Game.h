#pragma once

#include <vector>
#include "raylib.h"
#include "Obstacle.h"
#include "Player.h"
#include "Ray.h"

class Game
{
private:
	Player player;
	std::vector<Obstacle> obstacles;
	std::vector<Ray> rays;

public:
	Game();
	~Game();
	void ProcessInputs();
	void Render();
};

