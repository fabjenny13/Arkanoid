#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Rect
{
public:
	const int left;
	const int right;
	const int up;
	const int down;
public:
	Rect(int left, int right, int up, int down);
	Rect(Vec2 mid_pos, int width, int height);
	
	bool isOverLapping(Rect& other);
};

