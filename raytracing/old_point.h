#ifndef POINT_H
#define POINT_H
#include <math.h>
#include "old_angle.h"

class Point
{
public:
    Point();
    Point(double x, double y):_x(x), _y(y) {}
    Point(double radius, Angle alpha);
    double len(Point point2) const;
    Angle alpha(Point point2) const;

    double x() const;
    void setX(double value);
    double y() const;
    void setY(double value);
    void set(double x, double y);
    Point operator+(Point p2);
    Point operator-(Point p2);
    void rotation(Point center, Angle rotation);
    Point rotation(Point center, Angle rotation) const;

private:
    double _x;
    double _y;
};

#endif // POINT_H
