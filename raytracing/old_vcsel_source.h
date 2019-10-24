#ifndef VCSLSOURCE_H
#define VCSLSOURCE_H
#include "old_source.h"
#include "normal_distribution.h"
#include "uniform_real_distribution.h"

class VCSEL: public Source
{
public:
    VCSEL();
    VCSEL(Point center, Angle direction, Angle FWHM, double len);
    ~VCSEL() override;
    void change(Point center, Angle direction, Angle FWHM, double len);
    old_Ray genRay(double E, const normalSpectrum *spec) override;
private:
    Point _center = {0,0};
    Angle _direction = 0;
    Angle _FWHM = 30;
    double _len;
    NormalDistribution *_d;
    UniformRealDistribution *_dr;
};

#endif // VCSLSOURCE_H
