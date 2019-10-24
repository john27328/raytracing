#ifndef RAYTRACING_H
#define RAYTRACING_H
#include "old_edge.h"
#include "screen.h"
#include "old_shader.h"

class RayTracing
{
public:
    RayTracing(oldEdgeList *edgeList, RayList *rayList = nullptr);
    void trace(const old_Ray ray);

private:
    bool _draw;
//    Screen *_screen = nullptr;
    oldEdgeList *_edgeList = nullptr;
    RayList *_rayList = nullptr;
    int maxSegments = CNST::maxRaySegments;
};

#endif // RAYTRACING_H
