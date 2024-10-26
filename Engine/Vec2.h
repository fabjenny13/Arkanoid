#pragma once
class Vec2
{
public:
	int x;
	int y;
public:
	Vec2() = default;
	Vec2(int x, int y);
	Vec2 operator+(Vec2& rhs) const;
	Vec2& operator+=(Vec2& rhs);
	Vec2 operator*(int rhs) const;
	Vec2& operator*=(int rhs);

};

