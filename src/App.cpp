#include "App.h"

App::App()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raycaster");
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

		game_.render_debug();
		game_.render_3d();

		DrawFPS(static_cast<int>(fps_pos_.x), static_cast<int>(fps_pos_.y));
		EndDrawing();
	}
}
