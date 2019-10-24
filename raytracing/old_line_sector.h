#ifndef LINESECTOR_H
#define LINESECTOR_H
#include "old_edge.h"

class LineSector : public Edge
{
public:
    LineSector();
    LineSector(Point point1, Point point2, Point pointIn, QBrush brush);
    ~LineSector() override;
    old_Ray intersectionRayLen(const old_Ray &ray) const override;
    void draw(QPainter *painter, Screen *screen) override;
    Angle normal(const Point &point) const;
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    LineSector *clone() override;
private:
    Point _point1;
    Point _point2;
    Point _pointIn;
    double _refractiveIndexIn;
    double _refractiveIndexOut;
    bool pointsOnOneSide(const Point &point1, const Point &point2) const;
};

#endif // LINESECTOR_H
