#include "Rect.h"

Rect::Rect(float left, float right, float up, float down)
    :
    left(left),
    right(right),
    up(up),
    down(down)
{
}

Rect::Rect(Vec2 mid_pos, float width, float height)
    :
    left(mid_pos.x - width/2),
    right(mid_pos.x + width/2),
    up(mid_pos.y - height/2),
    down(mid_pos.y + height/2)
{
}

Rect Rect::GetExpanded(float offset) const
{
    return Rect(left - offset, right + offset, up - offset, down + offset);
}

bool Rect::isOverLapping(Rect& other) const
{
    return (left<=other.right && right >= other.left && up <= other.down && down >= other.up);
}

Rect Rect::FromCenter(Vec2 pos, float width, float height)
{
    return Rect(pos, width, height);
}

Vec2 Rect::GetCenter() const
{
    return  Vec2((left + right) / 2.0f, (up + down) / 2.0f);
}
