#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 pos, Vec2 vel)
	:
	pos(pos),
	vel(vel),
	rect(pos, radius, radius)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
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

void Ball::Move(float dt)
{
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;

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

