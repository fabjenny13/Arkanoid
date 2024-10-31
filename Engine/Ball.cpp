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
	const Rect rect = GetRect();
	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	else if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
	}
	else if (rect.down >= walls.down)
	{
		pos.y -= rect.down - walls.down;
		ReboundY();
	}
	else if (rect.up <= walls.up)
	{
		pos.y += walls.up - rect.up;
		ReboundY();
	}
}

void Ball::Update(float dt)
{
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;
}

Rect Ball::GetRect() const
{
	return Rect::FromCenter(pos, radius, radius);
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

