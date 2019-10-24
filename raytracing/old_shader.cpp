#include "old_shader.h"

Shader::Shader()
{

}

Shader::Shader(old_Edge *edge):
    _edge(edge)
{

}

void Shader::draw(QPainter *painter, Screen *screen)
{
    if (_edge)
    _edge->draw(painter, screen);
}

old_Edge *Shader::edge()
{
    return _edge;
}

void Shader::moving(Point shift, Angle rotation)
{
    if (_edge)
        _edge->moving(shift, rotation);
}

void Shader::moving(Point localCenter, Point shift, Angle rotation)
{
    if (_edge)
        _edge->moving(localCenter, shift, rotation);
}

old_Edge *Shader::getEdge()
{
    if (_edge)
        return _edge->getEdge();
    else
        return nullptr;
}
