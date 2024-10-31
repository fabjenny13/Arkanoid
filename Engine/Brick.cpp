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
	if (!destroyed && ball.GetRect().isOverLapping(rect))
	{
		destroyed = true;
		ball.ReboundY();
	}
}
