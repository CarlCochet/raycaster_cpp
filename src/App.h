#pragma once

#include "raylib.h"

#include "Game.h"
#include "utils.h"

class App
{
private:
	const Vector2 fps_pos_{
		static_cast<float>(WINDOW_WIDTH) * 94.0f / 100.0f,
		static_cast<float>(WINDOW_HEIGHT) / 100.0f
	};

	Game game_{};

public:
	App();
	~App();

	void run();
};

