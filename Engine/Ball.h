#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"

class Ball
{
private:
	float radius = 7.0f;
	float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
	Rect rect;

	Vec2 resetPos;

public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 vel);
	void Draw(Graphics& gfx) const;
	void ReboundX();
	void ReboundY();
	void DoWallCollision(Rect& walls);
	void Update(float dt);
	Rect GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(Vec2& dir);
	void ResetPosition();
};