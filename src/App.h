#pragma once

#include "raylib.h"

class App
{
private:
	const int m_window_width{ 1600 };
	const int m_window_height{ 900 };

	const Vector2 m_fps_pos{
		static_cast<float>(m_window_width * 94 / 100),
		static_cast<float>(m_window_height / 100)
	};

public:
	App();
	~App();

	void Run();
};

