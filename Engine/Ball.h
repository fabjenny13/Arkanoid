#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Ball
{
private:
	Vec2 pos;
	Vec2 vel;
	int speed;
	int radius;
	Color c = Colors::White;
public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 vel, int radius, int speed);
	void Draw(Graphics& gfx) const;
	void KeepInBounds(int leftBound, int rightBound, int upBound, int downBound);
	void Move();
};