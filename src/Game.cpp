#include "Game.h"

Game::Game()
{
	player_.generate_raycasts(ray_count_, fov_, vision_range_);
	world_.generate_random();
}

void Game::process_inputs()
{
	if (IsKeyDown(KEY_W))
	{
		player_.move(Direction::forward);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_S))
	{
		player_.move(Direction::backward);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_A))
	{
		player_.move(Direction::left);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
	if (IsKeyDown(KEY_D))
	{
		player_.move(Direction::right);
		player_.update_raycasts(world_.get_lines(player_.get_position(), vision_range_));
	}
}

void Game::render() const
{
	world_.render();
	player_.render();
}
