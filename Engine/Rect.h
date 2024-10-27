#pragma once
#include "Vec2.h"

class Rect
{
public:
	int left;
	int right;
	int up;
	int down;
public:
	Rect() = default;
	Rect(int left, int right, int up, int down);
	Rect(Vec2 mid_pos, int width, int height);
	bool isOverLapping(Rect& other) const;
};

