#include "old_circle_array_src.h"

CircleArraySource::CircleArraySource()
{

}

CircleArraySource::~CircleArraySource()
{
    if (_rand) delete _rand;
    if (_src) delete _src;
}

CircleArraySource::CircleArraySource(Source *src, int n, Point center, double radius, Angle phi)
{
    _src = src;
    if (n < 1) n = 1;
    _nArray = n;
    _center = center;
    _radius = radius;
    _phi = phi;
    _rand = new UniformIntDistribution(0, n-1);
}

old_Ray CircleArraySource::genRay(double E, const normalSpectrum *spec)
{
    if(_src){
        int i = _rand->rand();
        old_Ray tmp = _src->genRay(E, spec);
        double r = tmp.point().len(_center);
        if (r != 0) {
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
}

Angle CircleArraySource::angle(int i)
{
    return i * 2 * CNST::PI / _nArray + _phi;
}

Point CircleArraySource::position(int i)
{
    double alpha = angle(i);
    return {_radius * cos(alpha), _radius * sin(alpha)};
}
