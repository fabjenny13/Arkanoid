#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"

class Ball
{
private:
	Vec2 pos;
	Vec2 vel;
	int speed;
	int radius;
	Color c = Colors::White;
	Rect rect;

public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 vel, int radius, int speed);
	void Draw(Graphics& gfx) const;
	void ReboundX();
	void ReboundY();
	void DoWallCollision(Rect& walls);
	void Move();
	Rect& GetRect();
};