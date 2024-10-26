#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 vel, int radius, int speed)
	:
	pos(pos),
	vel(vel),
	radius(radius),
	speed(speed)
{
}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawCircle(pos.x, pos.y,radius, c);
}

void Ball::KeepInBounds(int leftBound, int rightBound, int upBound, int downBound)
{
	if (pos.x <= leftBound || pos.x >= rightBound)
	{
		vel.x = -vel.x;
	}
	if (pos.y >= downBound || pos.y <= upBound)
	{
		vel.y = -vel.y;
	}
}

void Ball::Move()
{
	pos.x += vel.x*speed;
	pos.y += vel.y*speed;
}

