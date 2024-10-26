#include "Vec2.h"

Vec2::Vec2(int x, int y)
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

Vec2 Vec2::operator*(int rhs) const
{
	return Vec2(x*rhs, y*rhs);
}

Vec2& Vec2::operator*=(int rhs)
{
	return *this = *this * rhs;
}
