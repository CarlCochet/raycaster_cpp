#include "Player.h"

Player::Player(const Vector2 position, const Vector2 forward):
	position_{ position }, forward_{ forward }, raycasts_{}
{
}

Vector2 Player::get_position() const
{
	return position_;
}

void Player::render() const
{
	DrawCircleV(position_, 10.0f, YELLOW);

	for (const RayCast& raycast : raycasts_)
	{
		raycast.render();
	}

	DrawLineV(position_, Vector2Add(position_, Vector2Scale(forward_, 100.0f)), GREEN); 
}

void Player::move(const Direction direction)
{
	switch (direction) {
	case Direction::forward:
		position_ = Vector2Add(position_, forward_);
		break;
	case Direction::backward:
		position_ = Vector2Subtract(position_, forward_);
		break;
	case Direction::left:
		forward_ = Vector2Rotate(forward_, 0.1f);
		break;
	case Direction::right:
		forward_ = Vector2Rotate(forward_, -0.1f);
		break;
	}
}

void Player::generate_raycasts(const int ray_count, const int fov, const float max_length)
{
	const float rad_fov = static_cast<float>(fov) * 3.14159265358979323846f / 180.0f;
	const float angle_step = rad_fov / static_cast<float>(ray_count);

	for (int i{0} ; i < ray_count ; ++i)
	{
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
