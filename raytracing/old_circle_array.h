#ifndef ARRAY_H
#define ARRAY_H
#include "old_edge.h"

class CircleArray: public old_Edge
{
public:
    CircleArray();
    CircleArray(old_Edge *edge, int n, double radius, Point center, Angle phi = 0);
    CircleArray(old_Edge *edge, Point localCenter, int n, double radius, Point center, Angle phi = 0);
    CircleArray(oldEdgeList list, int n, double radius, Point center, Angle phi = 0);
    CircleArray(oldEdgeList list, Point localCenter, int n, double radius, Point center, Angle phi = 0);
    old_Ray intersectionRayLen(const old_Ray &rayIn) const override;
    void draw(QPainter *painter, Screen * screen) override;
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    CircleArray * clone() override;
private:
    oldEdgeList _list;
};

#endif // ARRAY_H
