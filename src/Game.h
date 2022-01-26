#pragma once

#include <vector>

#include "raylib.h"

#include "World.h"
#include "Player.h"
#include "utils.h"

class Game
{
private:
	Player player_{
		Vector2{static_cast<float>(WINDOW_WIDTH) / 4.0f, static_cast<float>(WINDOW_HEIGHT) / 2.0f},
		Vector2{1.0f, 0.0f}
	};
	World world_{};

	// Game options
	float vision_range_{ 2000.0f };
	int fov_{ 90 };
	int ray_count_{ (WINDOW_WIDTH / 2) + 1 };

public:
	Game();
	~Game() = default;

	void process_inputs(float delta);
	void render_debug() const;
	void render_3d() const;
};

