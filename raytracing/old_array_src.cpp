#include "old_array_src.h"

ArraySource::ArraySource()
{

}

ArraySource::ArraySource(Source *src, int n, Point center, Angle phi, double dl)
{
    _src = src;
    if (n < 1) n = 1;
    _nArray = n;
    _center = center;
    _phi = phi;
    _dx = fabs(dl);
    _rand = new UniformIntDistribution(0, n-1);
}

ArraySource::~ArraySource()
{
    if (_rand) delete _rand;
    if (_src) delete _src;
}

old_Ray ArraySource::genRay(double E, const normalSpectrum *spec)
{
    if(_src){
        int i = _rand->rand();
        old_Ray tmp = _src->genRay(E, spec);
        double r = tmp.point().len(_center);
        if (r != 0.) {
            Angle phi = angle(i);
            Angle alpha1 = tmp.point().alpha(_center);
            Angle alpha2 = alpha1 + phi;
            tmp.setPoint(_center + Point(r * cos(alpha2), r * sin(alpha2)) + position(i));
            tmp.setAlpha((tmp.alpha() + angle(i)).fromNPiToPi());
        } else {
            tmp.setPoint(_center + position(i));
            tmp.setAlpha((tmp.alpha() + angle(i)).fromNPiToPi());
        }
        return tmp;
    }
    return  old_Ray();
}

Angle ArraySource::angle(int i)
{
    return _phi;
}

Point ArraySource::position(int i)
{
    double r = _dx *((double(_nArray) - 1.) / 2. - i);
    return {r * cos(_phi), r * sin(_phi)};
}
