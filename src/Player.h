#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

#include "raylib.h"
#include "raymath.h"

#include "utils.h"
#include "RayCast.h"

class Player
{
private:
	Vector2 position_{ static_cast<float>(WINDOW_WIDTH) / 4.0f, static_cast<float>(WINDOW_HEIGHT) / 2.0f };
	Vector2 forward_{ 1.0f, 0.0f };
	std::vector<RayCast> raycasts_{};

public:
	Player() = default;
	Player(Vector2 position, Vector2 forward);
	~Player() = default;

	Vector2 get_position() const;

	void render() const;
	void render_3d() const;
	void move(Direction direction, float delta);
	void generate_raycasts(const int ray_count, const int fov, const float max_length);
	void update_raycasts(const std::vector<Line>& lines);

};

