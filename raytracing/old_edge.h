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

class Edge
{
public:
    Edge();
    virtual ~Edge();

    virtual old_Ray intersectionRayLen(old_Ray const &rayIn) const = 0;
    virtual void draw(QPainter *painter, Screen * screen) = 0;
    virtual void moving(Point shift, Angle rotation) = 0;
    virtual void moving(Point localCenter, Point shift, Angle rotation) = 0;
    virtual Edge* clone() = 0;
    virtual Edge *getEdge();
protected:
    QBrush _brush;
};

using EdgeSPtr = std::shared_ptr<Edge>;
using EdgeList = std::vector<EdgeSPtr>;


#endif // EDGE_H
