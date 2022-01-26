#include "Game.h"

Game::Game()
{
	player_.generate_raycasts(ray_count_, fov_, vision_range_);
	world_.generate_random();
	player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
}

void Game::process_inputs(float delta)
{
	// Player movements
	if (IsKeyDown(KEY_W))
	{
		player_.move(Direction::forward, delta);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_S))
	{
		player_.move(Direction::backward, delta);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_D))
	{
		player_.move(Direction::left, delta);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_A))
	{
		player_.move(Direction::right, delta);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}

	// Settings changes
	// FoV changes
	if (IsKeyDown(KEY_KP_ADD))
	{
		if (fov_ < 360) {
			++fov_;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
	if (IsKeyDown(KEY_KP_SUBTRACT))
	{
		if (fov_ > 2) {
			--fov_;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
	// Vision range changes
	if (IsKeyDown(KEY_UP))
	{
		if (vision_range_ < 3000) {
			vision_range_ += 10;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
	if (IsKeyDown(KEY_DOWN))
	{
		if (vision_range_ > 2) {
			vision_range_ -= 10;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
	// Ray count changes
	if (IsKeyDown(KEY_LEFT))
	{
		if (ray_count_ > 10) {
			ray_count_ -= 10;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		if (ray_count_ < ((WINDOW_WIDTH / 2) + 1)) {
			ray_count_ += 10;
			player_.generate_raycasts(ray_count_, fov_, vision_range_);
			player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
		}
	}
}

void Game::render_debug() const
{
	world_.render();
	player_.render();
}

void Game::render_3d() const
{
	player_.render_3d();
}

