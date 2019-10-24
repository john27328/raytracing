#include "old_point.h"

Point::Point():_x(0), _y(0) {}

Point::Point(double radius, Angle alpha)
{
    _x = radius * cos(alpha);
    _y = radius * sin(alpha);
}

double Point::len(Point point2) const
{
    return sqrt(pow(_x - point2._x, 2) + pow(_y - point2._y, 2));
}

Angle Point::alpha(Point point2) const
{
    double l = len(point2);
    Angle gamma = acos((point2.x() - _x) / l);
    if(point2.y() - _y < 0) gamma = - gamma;
    return gamma;
}

double Point::x() const
{
    return _x;
}

void Point::setX(double value)
{
    _x = value;
}

double Point::y() const
{
    return _y;
}

void Point::setY(double value)
{
    _y = value;
}

void Point::set(double x, double y)
{
    _x = x; _y = y;
}

Point Point::operator+(Point p2)
{
    return {_x + p2.x(), _y + p2.y()};
}

Point Point::operator-(Point p2)
{
    return {_x - p2.x(), _y - p2.y()};
}

void Point::rotation(Point center, Angle rotation)
{
    double radius = center.len(*this);
    Angle alpha1 = center.alpha(*this);
    Angle alpha2 = alpha1 + rotation;
    _x = center.x() + radius * cos(alpha2);
    _y = center.y() + radius * sin(alpha2);
}

Point Point::rotation(Point center, Angle rotation) const
{
    Point tmp = *this;
    tmp.rotation(center, rotation);
    return tmp;
}
