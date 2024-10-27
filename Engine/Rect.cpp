#include "Rect.h"

Rect::Rect(int left, int right, int up, int down)
    :
    left(left),
    right(right),
    up(up),
    down(down)
{
}

Rect::Rect(Vec2 mid_pos, int width, int height)
    :
    left(mid_pos.x - width/2),
    right(mid_pos.x + width/2),
    up(mid_pos.y - height/2),
    down(mid_pos.y + height/2)
{
}

bool Rect::isOverLapping(Rect& other)
{
    return (left<=other.right && right >= other.right && up <= other.down && down >= other.up);
}
