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

void RayCast::render_3d(int total_rays, int ray_index) const
{
	const float ray_length{ Vector2Distance(start_, end_) };

	if (ray_length < length_-1) {
		const float log_length{ (1 - log10((ray_length * 0.01f) + 1)) };

		const int rect_width{ (WINDOW_WIDTH / 2) / total_rays };
		const int rect_height{ static_cast<int>(ceil(static_cast<float>(WINDOW_HEIGHT) / (ray_length * 0.1f))) };

		const int top_x{ (rect_width * ray_index) + (WINDOW_WIDTH / 2) };
		const int top_y{ (WINDOW_HEIGHT - rect_height) / 2 };

		Color blue_fade{
			0,
			static_cast<unsigned char>(static_cast<float>(241) * log_length),
			static_cast<unsigned char>(static_cast<float>(121) * log_length),
			255
		};

		blue_fade = wall_angle_ > 1.0f ? blue_fade : Color{
			static_cast<unsigned char>(static_cast<float>(blue_fade.r) * 0.9f),
			static_cast<unsigned char>(static_cast<float>(blue_fade.g) * 0.9f),
			static_cast<unsigned char>(static_cast<float>(blue_fade.b) * 0.9f),
			blue_fade.a
		};

		DrawRectangle(top_x, top_y, rect_width, rect_height, blue_fade);
	}
}

void RayCast::update(const Vector2 player_pos, const Vector2 player_dir)
{
	start_ = player_pos;
	end_ = Vector2Add(start_, Vector2Scale(Vector2Rotate(player_dir, angle_), length_));
}

void RayCast::compute_collision(const std::vector<Line>& lines)
{
	// Algorithm adapted from https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
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

				wall_angle_ = Vector2Angle(line.a, line.b);
			}
		}
	}
}
