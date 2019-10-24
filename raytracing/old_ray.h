#ifndef RAY_H
#define RAY_H

#include <vector>
#include "old_point.h"
#include "const.h"
#include <QDebug>
#include <random>
#include "old_angle.h"
#include "normal_spectrum.h"
#include <memory>

class old_Ray//:Point
{
public:
    old_Ray();
    old_Ray(double x,double y,Angle alpha, double E, const normalSpectrum *spec);
    old_Ray(Point pPoint, double alpha, double E, const normalSpectrum *spec);
    double x() const;
    double y() const;

    void *getEdge() const;
    void setEdge(void *value);
    bool pointOnRay(Point pPoint) const;

    Angle alpha() const;
    void setAlpha(Angle alpha);

    Point *pPoint();

    const Point *pPoint() const;

    void setPoint(const Point &pPoint);

    Point point() const;

    double len() const;
    void setLen(double len);

    const std::vector<double> &getE() const;
    void setE(const std::vector<double> &E);
    double E() const;

    Angle getNormal() const;
    void setNormal(const Angle &normal);

private:
    Angle _alpha = 0;
    Point _point;
    std::vector<double> _E;
    void *edge = nullptr;
    double _len = -1;
    Angle _normal = 0;
    void createE(double E, const normalSpectrum *spec);
};

using RayPath = std::vector<old_Ray>;
using RayList = std::vector<RayPath *>;

#endif // RAY_H
