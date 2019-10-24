#ifndef CIRCLEARRAY_H
#define CIRCLEARRAY_H

#include "old_point.h"
#include "old_source.h"
#include "uniform_int_distribution.h"
#include "old_shader.h"

class CircleArraySource:public Source
{
public:
    CircleArraySource();
    CircleArraySource(Source * src, int n, Point center, double radius, Angle phi = 0);
    ~CircleArraySource() override;
    old_Ray genRay(double E, const normalSpectrum *spec) override;
private:
    Source * _src = nullptr;
    int _nArray = 1;
    double _radius = 0;
    Point _center = {0,0};
    Angle _phi = 0;
    Angle angle(int i);
    Point position(int i);
    UniformIntDistribution *_rand;
};

#endif // CIRCLEARRAY_H
