#include "World.h"

World::World(const Vector2 world_size, const int cell_size):
	world_size_{ world_size }, cell_size_{ cell_size }
{
	// Not in init list to prevent incorrect init order
	width_ = { static_cast<int>(world_size_.x) / cell_size_ };
	height_ = { static_cast<int>(world_size_.y) / cell_size_ };

	// Make sure all memory is available for performance reasons
	grid_.reserve(width_* height_);
	lines_.reserve(width_* height_ * 4);
	nearby_lines_.reserve(width_* height_ * 4);
}

void World::generate_random()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	const std::uniform_int_distribution<std::mt19937::result_type> dist(0, 5);

	grid_.clear();
	lines_.clear();

	for (int y {0} ; y < height_ ; ++y)
	{
		for (int x {0} ; x < width_ ; ++x)
		{
			// Make the borders filled with obstacles
			if (x == 0 || x == width_-1 || y == 0 || y == height_-1)
			{
				grid_.emplace_back(1);
				generate_lines(x, y);
			}
			else
			{
				const int value{ static_cast<int>(dist(rng)) };

				// Otherwise only place obstacles where there are 1s
				if (value == 0) {
					grid_.emplace_back(1);
					generate_lines(x, y);
				}
				else
				{
					grid_.emplace_back(0);
				}
			}
		}
	}
}

void World::render() const
{
	// This is really only used as debug so no need to be fancy
	for (const Line& line : lines_)
	{
		DrawLineV(line.a, line.b, BLUE);
	}
}

std::vector<Line> World::get_lines(const Vector2 position, const float range)
{
	// Nearby lines are used to compute raycasts on a relevant subset of the obstacles
	nearby_lines_.clear();

	for (const Line& line : lines_)
	{
		// I don't know why this works, it should not
		if (Vector2Distance(position, line.a) < range || 
			Vector2Distance(position, line.b) < range)
		{
			nearby_lines_.emplace_back(line);
		}
	}

	return nearby_lines_;
}

void World::generate_lines(const int x, const int y)
{
	// 4 corners of the obstacle
	const float x1{ static_cast<float>(x * cell_size_) };
	const float x2{ static_cast<float>(x * cell_size_ + cell_size_) };
	const float y1{ static_cast<float>(y * cell_size_) };
	const float y2{ static_cast<float>(y * cell_size_ + cell_size_) };

	// Memory is already allocated so this is not too expensive
	// Only called on map generation anyway
	lines_.emplace_back(Line{
		Vector2{x1, y1},
		Vector2{x2, y1}
	});
	lines_.emplace_back(Line{
		Vector2{x1, y1},
		Vector2{x1, y2}
	});
	lines_.emplace_back(Line{
		Vector2{x2, y1},
		Vector2{x2, y2}
	});
	lines_.emplace_back(Line{
		Vector2{x1, y2},
		Vector2{x2, y2}
	});
}
