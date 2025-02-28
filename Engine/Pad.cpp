#include "Pad.h"

Pad::Pad(Vec2 pos, float width, float height, float speed)
	:
	pos(pos),
	speed(speed),
	width(width),
	height(height),
	rect(pos, width, height)
{
	resetPos = pos;
}

void Pad::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), c);
}

void Pad::KeepInBounds(Rect& walls)
{
	if (GetRect().left <= walls.left)
	{
		pos.x = walls.left + width / 2;
	}
	else if (GetRect().right >= walls.right)
	{
		pos.x = walls.right - width / 2;
	}

}

void Pad::ResetPosition()
{
	pos = resetPos;
}

Rect Pad::GetRect() const
{
	return Rect::FromCenter(pos, width, height);

}


void Pad::DoBallCollision(Ball& ball)
{
	if (ball.GetVelocity().y > 0 && ball.GetRect().isOverLapping(GetRect()))
	{
		if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetPosition() - pos).x) || (ball.GetPosition().x >= rect.left && ball.GetPosition().x <= rect.right))
		{
			float XDifference = ball.GetPosition().x - pos.x;
			Vec2 dir;

			float fixedXHalfWidth = 15.0f;
			if (abs(XDifference) < fixedXHalfWidth)
			{
				dir = { fixedXHalfWidth * 0.05f, -1.0f };
			}
			else
			{
				dir = { XDifference * 0.05f, -1.0f };
			}
			ball.SetDirection(dir);

		}

		else
		{
			ball.ReboundX();
		}
		

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


