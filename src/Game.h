#pragma once

#include <vector>

#include "raylib.h"

#include "World.h"
#include "Player.h"

class Game
{
private:
	Player player_{ Vector2{800.0f, 450.0f}, Vector2{1.0f, 0.0f} };
	World world_{};

	// Game options
	float vision_range_{ 1000.0f };
	int fov_{ 360 };
	int ray_count_{ 1600 };

public:
	Game();
	~Game() = default;
	void process_inputs();
	void render() const;
};

