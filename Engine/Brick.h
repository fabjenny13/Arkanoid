#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Rect.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
private:
	Color c;
	Rect rect;
	Vec2 pos; // center position
	float width;
	float height;
	bool destroyed = false;
	float padding = 2.0f;

public:
	Brick() = default;
	Brick(Vec2 pos, float width, float height, Color c);
	void Draw(Graphics& gfx) const;
	void DoBallCollision(Ball& ball);
};

