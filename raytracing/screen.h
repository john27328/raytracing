#ifndef SCREEN_H
#define SCREEN_H

#include "old_point.h"
#include "QPoint"
#include <memory>

class Screen
{
public:
    Screen();
    Screen(double x1, double y1, double x2, double y2);
    void setScreen(double x1, double y1, double x2, double y2);
    Point intToDouble(QPoint p);
    QPoint doubleToInt(Point p);
    void setResolution(int x, int y);

    int resolutionX() const;

    int resolutionY() const;

    Point range() const;


protected:
    int _resolutionX, _resolutionY;
    Point _point1, _point2;
};
using ScreenSPtr = std::shared_ptr<Screen>;

#endif // SCREEN_H
