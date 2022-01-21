#pragma once

#include "raylib.h"

enum Direction {
	Forward,
	Backward
};

struct Line {
	Vector2 A;
	Vector2 B;
};