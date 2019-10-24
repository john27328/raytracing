#ifndef CIRCLE_H
#define CIRCLE_H
#include "old_edge.h"
#include <math.h>
#include "const.h"

class Circle : public Edge
{
public:
    //Circle(Point center, double r, QBrush brush);
    Circle(double x, double y, double r, QBrush brush);
    Circle(Point center, double r, QBrush brush);
    old_Ray intersectionRayLen(const old_Ray &ray0) const override;
    void draw(QPainter *painter, Screen * screen) override;
    Angle normal(const Point &point) const;
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    Circle *clone() override;
protected:
    Point _center;
    double _radius;
    bool rayIntersectionWithACircle(old_Ray ray, Point &point1, Point &point2) const;

};

#endif // CIRCLE_H
