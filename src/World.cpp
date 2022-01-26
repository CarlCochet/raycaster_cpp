#include "World.h"

World::World(const Vector2 world_size, const int cell_size):
	world_size_{ world_size }, cell_size_{ cell_size }
{
	width_ = { static_cast<int>(world_size_.x) / cell_size_ };
	height_ = { static_cast<int>(world_size_.y) / cell_size_ };

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
			if (x == 0 || x == width_-1 || y == 0 || y == height_-1)
			{
				grid_.emplace_back(1);
				generate_lines(x, y);
			}
			else
			{
				const int value{ static_cast<int>(dist(rng)) };

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
	const int size{ static_cast<int>(grid_.size()) };

	for (int i {0} ; i < size ; ++i)
	{
		const int x { i % width_ };
		const int y { i / height_ };

		if (grid_[i] == 1)
		{
			DrawRectangle(x, y, cell_size_, cell_size_, WHITE);
		}
	}
}

std::vector<Line> World::get_lines(const Vector2 position, const float range)
{
	nearby_lines_.clear();

	for (const Line& line : lines_)
	{
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
	const float x1{ static_cast<float>(x * cell_size_) };
	const float x2{ static_cast<float>(x * cell_size_ + cell_size_) };
	const float y1{ static_cast<float>(y * cell_size_) };
	const float y2{ static_cast<float>(y * cell_size_ + cell_size_) };

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
