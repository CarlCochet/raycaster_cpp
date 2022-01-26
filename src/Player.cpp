#include "Player.h"

Player::Player(const Vector2 position, const Vector2 forward):
	position_{ position }, forward_{ forward }, raycasts_{}
{
	// Make sure all memory is available for performance reasons
	raycasts_.reserve(WINDOW_WIDTH);
}

Vector2 Player::get_position() const
{
	return position_;
}

void Player::render() const
{
	for (const RayCast& raycast : raycasts_)
	{
		raycast.render();
	}

	DrawLineV(position_, Vector2Add(position_, Vector2Scale(forward_, 100.0f)), GREEN);
	DrawCircleV(position_, 10.0f, YELLOW);
}

void Player::render_3d() const
{
	const int ray_count{ static_cast<int>(raycasts_.size()) };

	for (unsigned i {0} ; i < ray_count; ++i)
	{
		raycasts_[i].render_3d(ray_count, i);
	}
}

void Player::move(const Direction direction, float delta)
{
	switch (direction) {
	case Direction::forward:
		position_ = Vector2Add(position_, Vector2Scale(forward_, 100.0f * delta));
		break;
	case Direction::backward:
		position_ = Vector2Subtract(position_, Vector2Scale(forward_, 100.0f * delta));
		break;
	case Direction::left:
		forward_ = Vector2Rotate(forward_, 2.0f * delta);
		break;
	case Direction::right:
		forward_ = Vector2Rotate(forward_, -2.0f * delta);
		break;
	}
}

void Player::generate_raycasts(const int ray_count, const int fov, const float max_length)
{
	const float rad_fov = static_cast<float>(fov) * 3.14159265358979323846f / 180.0f;
	const float angle_step = rad_fov / static_cast<float>(ray_count);
	const int half_count{ ray_count / 2 }; // To center the rays arc around the player direction
	raycasts_.clear();

	for (int i{-half_count} ; i < half_count; ++i)
	{
		// Memory is already allocated so this is not TOO expensive
		// Only called on startup and setting changes anyway
		raycasts_.emplace_back(RayCast{
			position_,
			forward_,
			static_cast<float>(i) * angle_step,
			max_length
		});
	}
}

void Player::update_raycasts(const std::vector<Line>& lines)
{
	for (RayCast& raycast : raycasts_)
	{
		raycast.update(position_, forward_);
		raycast.compute_collision(lines);
	}
}
