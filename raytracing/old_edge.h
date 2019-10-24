#ifndef EDGE_H
#define EDGE_H

#include "old_ray.h"
#include <tuple>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QBrush>
#include <QRectF>
#include "screen.h"
#include <QDebug>
#include <memory>

using ReflactionBool = bool;

class old_Edge

{
public:
    old_Edge();
    virtual ~old_Edge();

    virtual old_Ray intersectionRayLen(old_Ray const &rayIn) const = 0;
    virtual void draw(QPainter *painter, Screen * screen) = 0;
    virtual void moving(Point shift, Angle rotation) = 0;
    virtual void moving(Point localCenter, Point shift, Angle rotation) = 0;
    virtual old_Edge* clone() = 0;
    virtual old_Edge *getEdge();
protected:
    QBrush _brush;
};

using oldEdgeSPtr = std::shared_ptr<old_Edge>;
using oldEdgeList = std::vector<oldEdgeSPtr>;


#endif // EDGE_H
