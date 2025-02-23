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
	Rect GetExpanded(float offset) const;
	bool isOverLapping(Rect& other) const;
	static Rect FromCenter(Vec2 pos, float width, float height);
	Vec2 GetCenter() const;
};

