#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 vel, int radius, int speed)
	:
	pos(pos),
	vel(vel),
	radius(radius),
	speed(speed),
	rect(pos, radius, radius)
{
}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawCircle(pos.x, pos.y,radius, c);
}

void Ball::DoWallCollision(Rect& walls)
{
	if (pos.x <= walls.left || pos.x >= walls.right)
	{
		ReboundX();
	}
	if (pos.y >= walls.down || pos.y <= walls.up)
	{
		ReboundY();
	}
}

void Ball::Move()
{
	pos.x += vel.x*speed;
	pos.y += vel.y * speed;
	rect.left = pos.x - radius / 2;
	rect.right = pos.x + radius / 2;
	rect.up = pos.y - radius / 2;
	rect.down = pos.y + radius / 2;
}

Rect& Ball::GetRect()
{
	return rect;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

