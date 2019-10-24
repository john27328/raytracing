#include "old_raytracing.h"

RayTracing::RayTracing(EdgeList *edgeList, RayList *rayList)
{
    _edgeList = edgeList;
    _rayList = rayList;
    if(rayList) _draw = 1;
    else _draw = 0;
}

void RayTracing::trace(const old_Ray ray)
{
    old_Ray rayTmp = ray;
    RayPath* path = nullptr;
    if(_draw) {
        path = new RayPath;
        _rayList->push_back(path);
    }
    if(_draw) path->push_back(rayTmp);
    //EdgeList::iterator pMin;
    for(int i = 0; i < maxSegments; i++)
    {
        auto p = _edgeList->begin();
        auto pMin = p;
        old_Ray rayMin; rayMin.setLen(-1);
        for(; p != _edgeList->end(); ++p)
        {
            old_Ray newRay = (*p)->intersectionRayLen(rayTmp);
            if(newRay.len() > 0  && (newRay.len() < rayMin.len() || rayMin.len() < 0)) {
                pMin = p;
                rayMin = newRay;
            }
        }

        if (rayMin.len() <=0){ // если в молоко
            double dx = 150 * cos(rayTmp.alpha());
            double dy = 150 * sin(rayTmp.alpha());
            rayTmp.setPoint(rayTmp.point() + Point(dx, dy));
            if(_draw) path->push_back(rayTmp);
            break;
        }

        rayTmp = rayMin;
        if(_draw) path->push_back(rayTmp);

        // убивать лучи с малым ипоглощением
        if(rayTmp.E() / ray.E() < CNST::minE){
            break;
        }
    }
}
