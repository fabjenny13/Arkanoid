#pragma once
#include <cmath>

class Vec2
{
public:
	float x;
	float y;
public:
	Vec2() = default;
	Vec2(float x, float y);
	Vec2 operator+(Vec2& rhs) const;
	Vec2& operator+=(Vec2& rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
	Vec2 operator-(Vec2& rhs) const;

	float GetLengthSq() const;
	float GetLength() const;
	Vec2& GetNormalized() const;

};

