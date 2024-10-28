#pragma once
#include "Vec2.h"

class Rect
{
public:
	float left;
	float right;
	float up;
	float down;
public:
	Rect() = default;
	Rect(float left, float right, float up, float down);
	Rect(Vec2 mid_pos, float width, float height);
	bool isOverLapping(Rect& other) const;
};

