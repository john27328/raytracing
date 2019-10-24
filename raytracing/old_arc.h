#ifndef ARC_H
#define ARC_H
#include "old_edge.h"
#include "old_circle.h"

class Arc: public Circle
{
public:

    Arc(double x, double y, double r, QBrush brush,
        Angle alpha1, Angle alpha2, Angle alpha);
    Arc(Point center, double r, QBrush brush, Angle startAngle,
        Angle spanAngle);
    old_Ray intersectionRayLen(const old_Ray &ray) const override;
    void draw(QPainter *painter, Screen * screen) override;
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    Arc * clone() override;

private:
    bool pointOnArc(Point point) const;
    Angle _startAngle, _spanAngle;
    bool rayIntersectionWithACircle(old_Ray ray, Point &point1, Point &point2);
    void counterClockwise(Angle alpha1, Angle alpha2, Angle alpha);
};

#endif // ARC_H
