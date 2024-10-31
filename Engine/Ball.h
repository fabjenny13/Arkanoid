#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"

class Ball
{
private:
	Vec2 pos;
	Vec2 vel;
	float radius = 7.0f;
	Rect rect;

public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 vel);
	void Draw(Graphics& gfx) const;
	void ReboundX();
	void ReboundY();
	void DoWallCollision(Rect& walls);
	void Update(float dt);
	Rect GetRect() const;
};