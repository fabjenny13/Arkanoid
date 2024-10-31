#include "Pad.h"
#include <iostream>

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
	gfx.DrawRect(rect, c);
}

void Pad::Move(float delta_x, float dt)
{
	pos.x += delta_x * speed * dt;

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

void Pad::DoBallCollision(Ball& ball)
{
	if (ball.GetRect().isOverLapping(rect))
	{
		std::cout << "Collided." << std::endl;
		ball.ReboundY();
	}
}

void Pad::Update(MainWindow& wnd, float dt, Rect& walls)
{
	int input = 0.0f;

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		input = -1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		input = 1.0f;
	}
	Move(input, dt);
	KeepInBounds(walls);
}


