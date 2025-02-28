#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Ball.h"
#include "MainWindow.h"
#include <cmath>

class Pad
{
private:
	Vec2 pos; // center pos
	Color c = Colors::White;
	float width;
	float height;
	float speed; //can only move on x axis
	Rect rect;

	Vec2 resetPos;
public:
	Pad() = default;
	Pad(Vec2 pos, float width, float height, float speed);
	void Draw(Graphics& gfx) const;
	void DoBallCollision(Ball& ball);
	void Update(MainWindow& wnd, float dt);
	void KeepInBounds(Rect& walls);
	void ResetPosition();
	Rect GetRect() const;
	
};

