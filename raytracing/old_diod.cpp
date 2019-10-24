#include "old_diod.h"

Diod::Diod()
{
    _center = {0,0};
    _direction = 0;
    _FWHM = 0;
    _d = new NormalDistribution(_direction, _FWHM);
}

Diod::Diod(Point center, Angle direction, Angle FWHM)
{
    _center = center;
    _direction = direction;
    _FWHM = FWHM;
    _d = new NormalDistribution(_direction, _FWHM);
}

Diod::~Diod()
{
    delete _d;
    _d = nullptr;
}

void Diod::change(Point center, Angle direction, Angle FWHM)
{
    delete _d;
    _center = center;
    _direction = direction;
    _FWHM = FWHM;
    _d = new NormalDistribution(_direction, _FWHM);
}

old_Ray Diod::genRay(double E, const normalSpectrum *spec)
{
    old_Ray ray(_center, Angle(_d->rand()).from0to2Pi(), E, spec);
    return ray;
}

