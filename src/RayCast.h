#pragma once

#include <vector>
#include <cmath>

#include "raylib.h"
#include "raymath.h"

#include "utils.h"

class RayCast
{
private:
	Vector2 start_{ 0.0f, 0.0f };
	Vector2 end_{ 1.0f, 0.0f };
	float angle_{ 0.0f };
	float length_{ 1.0f };
	float wall_angle_{ 0.0f };

public:
	RayCast(Vector2 start, Vector2 direction, float angle, float length);
	~RayCast() = default;
	void render() const;
	void render_3d(int total_rays, int ray_index) const;
	void update(Vector2 player_pos, Vector2 player_dir);
	void compute_collision(const std::vector<Line>& lines);

};

