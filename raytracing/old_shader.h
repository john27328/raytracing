#ifndef SHADER_H
#define SHADER_H
#include "old_edge.h"

class Shader: public old_Edge
{
public:
    Shader();
    Shader(old_Edge *edge);
    old_Ray intersectionRayLen(const old_Ray &rayIn) const override = 0;
    void draw(QPainter *painter, Screen *screen) override;
    old_Edge *edge();
    void moving(Point shift, Angle rotation) override;
    void moving(Point localCenter, Point shift, Angle rotation) override;
    old_Edge *getEdge() override;
protected:
    old_Edge *_edge = nullptr;
};

#endif // SHADER_H
