#pragma once

#include "raylib.h"

enum class Direction {
	forward,
	backward,
	left,
	right
};

struct Line {
	Vector2 a;
	Vector2 b;
};