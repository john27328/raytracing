#ifndef ARRAYSOURCE_H
#define ARRAYSOURCE_H

#include "old_point.h"
#include "old_source.h"
#include "uniform_int_distribution.h"

class ArraySource:public Source
{
public:
    ArraySource();
    ArraySource(Source * src, int n, Point center, Angle phi, double dl);
    ~ArraySource() override;
    old_Ray genRay(double E, const normalSpectrum *spec) override;
private:
    Source * _src = nullptr;
    int _nArray = 1;
    double _dx = 1;
    Point _center = {0,0};
    Angle _phi = 0;
    Angle angle(int i);
    Point position(int i);
    UniformIntDistribution *_rand;
};

#endif // ARRAYSOURCE_H
