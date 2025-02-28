#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 pos, Vec2 dir)
	:
	pos(pos),
	rect(pos, radius, radius)

{
	SetDirection(dir);
	resetPos = pos;
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

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

void Ball::SetDirection(Vec2& dir)
{
	vel =  dir.GetNormalized() * speed;
}

void Ball::ResetPosition()
{
	pos = resetPos;;
}


void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

