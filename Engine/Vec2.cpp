#include "Vec2.h"

Vec2::Vec2(float x, float y)
	:
	x(x),
	y(y)
{
}

Vec2 Vec2::operator+(Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(Vec2& rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x*rhs, y*rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

float Vec2::GetLengthSq() const
{
	return x * x + y * y;
}
