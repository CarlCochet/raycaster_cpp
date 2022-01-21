#include "App.h"

App::App()
{
	InitWindow(m_window_width, m_window_height, "Raycaster");
	SetTargetFPS(144);
}

App::~App()
{
	CloseWindow();
}

void App::Run()
{
	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);



		DrawFPS(static_cast<int>(m_fps_pos.x), static_cast<int>(m_fps_pos.y));
		EndDrawing();
	}
}
