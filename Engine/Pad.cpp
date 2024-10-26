#include "Pad.h"

Pad::Pad(Vec2 pos, int width, int height, int speed)
	:
	pos(pos),
	width(width),
	height(height),
	speed(speed)
{
}

void Pad::Draw(Graphics& gfx)
{
	gfx.DrawRect(width, height, pos.x, pos.y, c);
}

void Pad::Move(int delta_x)
{
	pos.x += delta_x*speed;
}

void Pad::KeepInBounds(int leftBound, int rightBound)
{
	if(pos.x <= leftBound)
	{
		pos.x = leftBound;
	}
	else if (pos.x >= rightBound)
	{
		pos.x = rightBound;
	}
}


