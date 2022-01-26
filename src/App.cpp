#include "App.h"

App::App()
{
	InitWindow(window_width_, window_height_, "Raycaster");
	SetTargetFPS(144);
}

App::~App()
{
	CloseWindow();
}

void App::run()
{
	while (!WindowShouldClose())
	{
		game_.process_inputs(GetFrameTime());

		BeginDrawing();
		ClearBackground(BLACK);

		game_.render();

		DrawFPS(static_cast<int>(fps_pos_.x), static_cast<int>(fps_pos_.y));
		EndDrawing();
	}
}
