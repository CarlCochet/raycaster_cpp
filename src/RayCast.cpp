#include "RayCast.h"

RayCast::RayCast(Vector2 start, Vector2 direction, float angle, float length):
	start_{start}, angle_{ angle }, length_{length}
{
	end_ = Vector2Add(start_, Vector2Scale(Vector2Rotate(direction, angle_), length_));
}

void RayCast::render() const
{
	DrawLineV(start_, end_, WHITE);
}

void RayCast::update(const Vector2 player_pos, const Vector2 player_dir)
{
	start_ = player_pos;
	end_ = Vector2Add(start_, Vector2Scale(Vector2Rotate(player_dir, angle_), length_));
}

void RayCast::compute_collision(const std::vector<Line>& lines)
{
	for (const Line& line : lines)
	{
		const Vector2 s1{ line.b.x - line.a.x, line.b.y - line.a.y };
		const Vector2 s2{ end_.x - start_.x, end_.y - start_.y };

		const float denominator{ -s2.x * s1.y + s1.x * s2.y };

		if (denominator > 0 || denominator < 0)
		{
			const float s{ (-s1.y * (line.a.x - start_.x) + s1.x * (line.a.y - start_.y)) / denominator };
			const float t{ (s2.x * (line.a.y - start_.y) - s2.y * (line.a.x - start_.x)) / denominator };

			if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
			{
				end_.x = line.a.x + (t * s1.x);
				end_.y = line.a.y + (t * s1.y);
			}
		}
	}
}
