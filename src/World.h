#pragma once

#include <vector>
#include <random>

#include "raylib.h"
#include "raymath.h"

#include "utils.h"

class World
{
private:
	std::vector<int> grid_{};
	std::vector<Line> lines_{};
	std::vector<Line> nearby_lines_{};
	Vector2 world_size_{ static_cast<float>(WINDOW_WIDTH) / 2.0f, WINDOW_HEIGHT };
	int cell_size_{ 50 };
	int width_{ static_cast<int>(world_size_.x) / cell_size_ };
	int height_{ static_cast<int>(world_size_.y) / cell_size_ };

public:
	World() = default;
	World(Vector2 world_size, int cell_size);
	~World() = default;

	void generate_random();
	void render() const;
	std::vector<Line> get_lines(const Vector2 position, const float range);
	void generate_lines(const int x, const int y);

};

