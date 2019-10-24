#include "screen.h"

Screen::Screen()
{
    _resolutionX = 0;
    _resolutionY = 0;
    _point1.setX(-1);
    _point2.setX(-1);
    _point1.setY(1);
    _point2.setY(1);
}

Screen::Screen(double x1, double y1, double x2, double y2)
{
    _resolutionX = 0;
    _resolutionY = 0;
    _point1.setX(x1);
    _point2.setX(x2);
    _point1.setY(y1);
    _point2.setY(y2);
}

void Screen::setScreen(double x1, double y1, double x2, double y2)
{
    _point1.setX(x1);
    _point2.setX(x2);
    _point1.setY(y1);
    _point2.setY(y2);
}

Point Screen::intToDouble(QPoint p)
{
    Point pd = {(double)p.x() / _resolutionX * (_point2.x() - _point1.x()) + _point1.x(),
                -(double)p.y() / _resolutionY * (_point2.y() - _point1.y()) + _point2.y() };
    return pd;
}

QPoint Screen::doubleToInt(Point p)
{
    QPoint pi((p.x() - _point1.x()) / (_point2.x() - _point1.x()) * _resolutionX + 0.5,
              _resolutionY - (p.y() - _point1.y()) / (_point2.y() - _point1.y()) * _resolutionY + 0.5);
    return pi;
}

void Screen::setResolution(int x, int y)
{
    _resolutionX = x;
    _resolutionY = y;
}

int Screen::resolutionX() const
{
    return _resolutionX;
}

int Screen::resolutionY() const
{
    return _resolutionY;
}

Point Screen::range() const
{
    double rangeX = _point2.x() - _point1.x();
    double rangeY = _point2.y() - _point1.y();
    return {rangeX, rangeY};
}
