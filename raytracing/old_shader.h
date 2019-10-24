#ifndef SHADER_H
#define SHADER_H
#include "old_edge.h"

class Shader: public Edge
{
public:
    Shader();
    Shader(Edge *edge);
    old_Ray intersectionRayLen(const old_Ray &rayIn) const override = 0;
    void draw(QPainter *painter, Screen *screen) override;
    Edge *edge();
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    Edge *getEdge() override;
protected:
    Edge *_edge = nullptr;
};

#endif // SHADER_H
