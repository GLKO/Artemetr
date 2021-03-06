#pragma once

struct Point
{
    Point() {}
    Point (int x, int y) {X = x; Y = y;}
    int X = -1;
    int Y = -1;

    bool operator == (const Point &anotherPoint) const
    {
        if (this->X == anotherPoint.X && this->Y == anotherPoint.Y)
            return true;
        return false;
    }

    bool operator != (const Point &anotherPoint) const
    {
        if (this->X != anotherPoint.X || this->Y != anotherPoint.Y)
            return true;
        return false;
    }

    void operator = (const Point& anotherPoint)
    {
        X = anotherPoint.X;
        Y = anotherPoint.Y;
    }
};
