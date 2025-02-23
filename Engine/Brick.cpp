#include "Brick.h"

Brick::Brick(Vec2 pos, float width, float height, Color c)
	:
	pos(pos),
	rect(pos, width, height),
	c(c),
	width(width),
	height(height)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding), c);
	}
}

void Brick::DoBallCollision(Ball& ball)
{
	Vec2 ballPos = ball.GetPosition();

	if (!destroyed && ball.GetRect().isOverLapping(rect))
	{
		if (ballPos.x >= rect.left && ballPos.x <= rect.right)
		{
			ball.ReboundY();
		}
		else {
			ball.ReboundX();
		}
		destroyed = true;
	}
}

bool Brick::CheckCollision(const Ball& ball) const
{
	return (!destroyed && rect.isOverLapping(ball.GetRect()));
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckCollision(ball));

	Vec2 ballPos = ball.GetPosition();

	if (std::signbit(ball.GetVelocity().x) == std::signbit(ball.GetPosition().x - pos.x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else {
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
