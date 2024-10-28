#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Ball.h"

class Pad
{
private:
	Vec2 pos;
	Color c = Colors::White;
	float width;
	float height;
	float speed; //can only move on x axis
	Rect rect;
public:
	Pad() = default;
	Pad(Vec2 pos, float width, float height, float speed);
	void Draw(Graphics& gfx);
	void Move(float delta_x, float dt);
	void KeepInBounds(Rect& walls);
	void DoBallCollision(Ball& ball);
	
};

