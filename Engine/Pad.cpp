#include "Pad.h"

Pad::Pad(Vec2 pos, int width, int height, int speed)
	:
	pos(pos),
	speed(speed),
	width(width),
	height(height),
	rect(pos, width, height)
{
}

void Pad::Draw(Graphics& gfx)
{
	gfx.DrawRect(rect, c);
}

void Pad::Move(int delta_x)
{
	pos.x += delta_x*speed;
	rect.left = pos.x - width / 2;
	rect.right = pos.x + height / 2;
}

void Pad::KeepInBounds(Rect& walls)
{
	if(pos.x <= walls.left)
	{
		pos.x = walls.left;
	}
	else if (pos.x >= walls.right)
	{
		pos.x = walls.right;
	}
	rect.left = pos.x - width / 2;
	rect.right = pos.x + height / 2;
}


