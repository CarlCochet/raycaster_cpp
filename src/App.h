#pragma once

#include "raylib.h"

#include "Game.h"

class App
{
private:
	const int window_width_{ 1600 };
	const int window_height_{ 900 };

	const Vector2 fps_pos_{
		static_cast<float>(window_width_) * 94.0f / 100.0f,
		static_cast<float>(window_height_) / 100.0f
	};

	Game game_{};

public:
	App();
	~App();

	void run();
};

