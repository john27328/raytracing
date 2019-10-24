#include "old_vcsel_source.h"

VCSEL::VCSEL()
{
    _center = {0,0};
    _direction = 0;
    _FWHM = 0;
    _len = 0;
    _d = new NormalDistribution(_direction, _FWHM);
    _dr = new UniformRealDistribution(0, _len);
}

VCSEL::VCSEL(Point center, Angle direction, Angle FWHM, double len)
{
    _center = center;
    _direction = direction;
    _FWHM = FWHM;
    _len = len;
    _d = new NormalDistribution(_direction, _FWHM);
    _dr = new UniformRealDistribution(0, _len);
}

VCSEL::~VCSEL()
{
    delete _d;
    _d = nullptr;
}

void VCSEL::change(Point center, Angle direction, Angle FWHM, double len)
{
    _center = center;
    _direction = direction;
    _FWHM = FWHM;
    _len = len;
    _d = new NormalDistribution(_direction, _FWHM);
    _dr = new UniformRealDistribution(0, _len);
}

old_Ray VCSEL::genRay(double E, const normalSpectrum *spec)
{
    //изменить
    Angle alpha = Angle(_direction) + Angle(90_gr);
    double dl = (_dr->rand() - _len / 2.);
    Point dP(dl * cos(alpha), dl * sin(alpha));
    old_Ray ray(_center + dP, Angle(_d->rand()).from0to2Pi(), E, spec);
    return ray;
}
