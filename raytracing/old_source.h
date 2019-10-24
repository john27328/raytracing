#ifndef SOURCE_H
#define SOURCE_H
#include "old_ray.h"

class Source
{
public:
    Source();
    virtual ~Source(){}
    virtual old_Ray genRay(double E, const normalSpectrum *spec) = 0;
};

#endif // SOURCE_H
