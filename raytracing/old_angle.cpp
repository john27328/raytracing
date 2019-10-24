#include "old_angle.h"

Angle::Angle()
{

}

Angle::Angle(double alpha)
{
    _angle = alpha;
}

Angle::Angle(double alpha, bool grad)
{
    if(grad) _angle = alpha / 180. * CNST::PI;
    else _angle = alpha;
}

Angle Angle::operator+(Angle beta)
{
    return _angle + beta;
}

Angle Angle::operator+(double beta)
{
    return _angle + beta;
}

Angle Angle::operator-(Angle beta)
{
    return _angle - beta;
}

Angle Angle::operator-(double beta)
{
    return _angle - beta;
}

Angle Angle::operator*(Angle beta)
{
    return Angle(_angle * beta);
}

Angle Angle::operator*(double beta)
{
    return Angle(_angle * beta);
}

Angle Angle::from0to2Pi()
{
    if(_angle > 2 * CNST::PI)
        _angle = (_angle / (2 * CNST::PI)
                  - int(_angle / (2 * CNST::PI))) * 2 * CNST::PI;
    if(_angle < 0)
        _angle = (_angle / (2 * CNST::PI)
                  - int(_angle / (2 * CNST::PI)) + 1.) * 2 * CNST::PI;
    return _angle;
}

Angle Angle::fromNPiToPi()
{
    _angle+=CNST::PI;
    from0to2Pi();
    _angle-=CNST::PI;
    return _angle;
}

double Angle::gr()
{
    return _angle * 180. / CNST::PI;
}

Angle Angle::gr(double gr)
{
    return {gr, 1};
}

Angle::operator double() const
{
    return _angle;
}

long double operator "" _gr(long double grad)
{
    return grad / 180. * CNST::PI;
}

long double operator "" _gr(unsigned long long grad)
{
    return grad / 180. * CNST::PI;
}
