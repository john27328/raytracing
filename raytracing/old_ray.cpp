#include "old_ray.h"


old_Ray::old_Ray()
{
}

old_Ray::old_Ray(double x, double y, Angle alpha, double E, const normalSpectrum *spec)
{
    _point.set(x, y);
    this->_alpha = alpha;
    createE(E, spec);
}

old_Ray::old_Ray(Point point, double alpha, double E, const normalSpectrum *spec)
{
    _point = point;
    this->_alpha = alpha;
    createE(E, spec);
}

double old_Ray::x() const
{
    return _point.x();
}

double old_Ray::y() const
{
    return _point.y();
}

void *old_Ray::getEdge() const
{
    return edge;
}

void old_Ray::setEdge(void *value)
{
    edge = value;
}

bool old_Ray::pointOnRay(Point point2) const
{
    double pointAlpha = _point.alpha(point2);
    double deltaAlpha = pointAlpha - _alpha;
    double dAlpha = deltaAlpha / (2 * CNST::PI);
    bool ok = false;
    if(fabs(dAlpha - round(dAlpha)) < .1) {
        ok = true;
//            qDebug() << point2.x() - _point.x()<<point2.y() - _point.y()
//                     << _alpha * 180. / constants::pi
//                     << pointAlpha * 180. / constants::pi
//                     << ok;
    }

    return ok;

}

Angle old_Ray::alpha() const
{
    return _alpha;
}

void old_Ray::setAlpha(Angle alpha)
{
    _alpha = alpha;
}

Point *old_Ray::pPoint()
{
    return &_point;
}

const Point *old_Ray::pPoint() const
{
    return (&_point);
}

void old_Ray::setPoint(const Point &point)
{
    _point = point;
}

Point old_Ray::point() const
{
    return _point;
}

double old_Ray::len() const
{
    return _len;
}

void old_Ray::setLen(double len)
{
    _len = len;
}

const std::vector<double> &old_Ray::getE() const
{
    return _E;
}

void old_Ray::setE(const std::vector<double> &E)
{
    _E = E;
}

double old_Ray::E() const
{
    double E = 0;
    for(auto e: _E){
        E += e;
    }
    return E;
}

Angle old_Ray::getNormal() const
{
    return _normal;
}

void old_Ray::setNormal(const Angle &normal)
{
    _normal = normal;
}

void old_Ray::createE(double E, const normalSpectrum *spec)
{
    double summPow = 0;
    for(auto s: spec->power()){
        summPow +=s;
    }
    for(auto s: spec->power()){
        _E.push_back(E / summPow * s);
    }
}

