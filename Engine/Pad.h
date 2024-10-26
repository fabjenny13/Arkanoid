#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Pad
{
private:
	Vec2 pos;
	Color c = Colors::White;
	int width;
	int height;
	int speed; //can only move on x axis
public:
	Pad() = default;
	Pad(Vec2 pos, int width, int height, int speed);
	void Draw(Graphics& gfx);
	void Move(int delta_x);
	void KeepInBounds(int leftBound, int rightBound);
};

