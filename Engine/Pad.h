#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"

class Pad
{
private:
	Vec2 pos;
	Color c = Colors::White;
	int width;
	int height;
	int speed; //can only move on x axis
	Rect rect;
public:
	Pad() = default;
	Pad(Vec2 pos, int width, int height, int speed);
	void Draw(Graphics& gfx);
	void Move(int delta_x);
	void KeepInBounds(Rect& walls);
};

