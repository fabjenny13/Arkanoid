#include "Pad.h"

Pad::Pad(Vec2 pos, float width, float height, float speed)
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
	gfx.DrawRect(GetRect(), c);
}

void Pad::KeepInBounds(Rect& walls)
{
	if(GetRect().left <= walls.left)
	{
		pos.x = walls.left + width / 2;
	}
	else if (GetRect().right >= walls.right)
	{
		pos.x = walls.right - width / 2;
	}

}

Rect Pad::GetRect() const
{
	return Rect::FromCenter(pos, width, height);

}

void Pad::DoBallCollision(Ball& ball)
{
	if (ball.GetVelocity().y > 0 && ball.GetRect().isOverLapping(GetRect()))
	{
		ball.ReboundY();
	}
}

void Pad::Update(MainWindow& wnd, float dt)
{
	float input = 0.0f;

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}

}


