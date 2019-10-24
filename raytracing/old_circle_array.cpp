#include "old_circle_array.h"


CircleArray::CircleArray()
{

}

CircleArray::CircleArray(old_Edge *edge, int n, double radius, Point center, Angle phi)
{
    if (n < 1) n = 1;
    Angle dAlpha = 360_gr / n;
    for (int i = 0; i < n; i++){
        oldEdgeSPtr tmp(edge->clone());
        Angle rotation = i * dAlpha + phi;
        Point shift(radius, rotation);
        tmp->moving(shift + center, rotation);
        _list.push_back(tmp);
    }
}

CircleArray::CircleArray(old_Edge *edge, Point localCenter, int n, double radius, Point center, Angle phi)
{
    if (n < 1) n = 1;
    Angle dAlpha = 360_gr / n;
    for (int i = 0; i < n; i++){
        oldEdgeSPtr tmp(edge->clone());
        Angle rotation = i * dAlpha + phi;
        Point shift(radius, rotation);
        tmp->moving(localCenter, shift + center, rotation);
        _list.push_back(tmp);
    }
}

CircleArray::CircleArray(oldEdgeList list, int n, double radius, Point center, Angle phi)
{
    if (n < 1) n = 1;
    Angle dAlpha = 360_gr / n;
    for (int i = 0; i < n; i++){
        Angle rotation = i * dAlpha + phi;
        Point shift(radius, rotation);
        oldEdgeSPtr tmp;
        for (auto&j: list){
            tmp = oldEdgeSPtr(j->clone());
            tmp->moving(shift + center, rotation);
            _list.push_back(tmp);
        }
    }
}

CircleArray::CircleArray(oldEdgeList list, Point localCenter, int n, double radius, Point center, Angle phi)
{
    if (n < 1) n = 1;
    Angle dAlpha = 360_gr / n;
    for (int i = 0; i < n; i++){
        Angle rotation = i * dAlpha + phi;
        Point shift(radius, rotation);
        oldEdgeSPtr tmp;
        for (auto&j: list){
            tmp = oldEdgeSPtr(j->clone());
            tmp->moving(localCenter, shift + center, rotation);
        }
        _list.push_back(tmp);
    }
}

old_Ray CircleArray::intersectionRayLen(const old_Ray &rayIn) const
{
    old_Ray rayMin = rayIn; rayMin.setLen(-1);
    for(auto &i: _list){
        old_Ray rayTmp = i->intersectionRayLen(rayIn);
        if (rayTmp.len() > 0 &&
                (rayTmp.len() < rayMin.len() || rayMin.len() < 0)){
            rayMin = rayTmp;
        }
    }
    if (rayMin.len() < 0) return rayMin;
    return rayMin;
}

void CircleArray::draw(QPainter *painter, Screen *screen)
{
    for(auto &i: _list){
        i->draw(painter, screen);
    }
}

void CircleArray::moving(Point shift, Angle rotation)
{
    for(auto &i: _list){
        i->moving(shift, rotation);
    }
}

void CircleArray::moving(Point localCenter, Point shift, Angle rotation)
{
    for(auto &i: _list){
        i->moving(localCenter, shift, rotation);
    }
}

CircleArray *CircleArray::clone()
{
    return new CircleArray(*this);
}
