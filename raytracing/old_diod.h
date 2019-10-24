#ifndef DIOD_H
#define DIOD_H

#include "old_point.h"
#include "old_ray.h"
#include "normal_distribution.h"
#include "old_source.h"

class Diod: public Source
{
public:
    Diod();
    Diod(Point center, Angle direction, Angle FWHM);
    ~Diod() override;
    void change(Point center, Angle direction, Angle FWHM);
    old_Ray genRay(double E, const normalSpectrum *spec) override;

private:
    Point _center = {0,0};
    Angle _direction = 0;
    Angle _FWHM = 30;
    NormalDistribution *_d;
};

#endif // DIOD_H
