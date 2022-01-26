#pragma once

#include "raylib.h"

constexpr int WINDOW_HEIGHT = 900;
constexpr int WINDOW_WIDTH = 1600;

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