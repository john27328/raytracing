#include "old_arc.h"


Arc::Arc(double x, double y, double r, QBrush brush, Angle alpha1, Angle alpha2, Angle alpha):
    Circle(x, y, r, brush)
{
    counterClockwise(alpha1, alpha2, alpha);
}

Arc::Arc(Point center, double r, QBrush brush, Angle startAngle, Angle spanAngle):
    Circle(center, r, brush)

{
    if(spanAngle > 0){
        _startAngle = startAngle;
        _spanAngle = spanAngle;
    }
    else{
        _startAngle = startAngle + spanAngle;
        _spanAngle = - spanAngle;
    }
}

old_Ray Arc::intersectionRayLen(const old_Ray &ray) const
{
    old_Ray newRay = Circle::intersectionRayLen(ray);

    if(!pointOnArc(newRay.point())) {// если нет пересечения
        newRay.setLen(-1);
    }

    return newRay;
}

void Arc::draw(QPainter *painter, Screen *screen)
{
    QPoint center = screen->doubleToInt(_center);
    int R = _radius / screen->range().x()
            * screen->resolutionX();
    int x1 = center.x() - R;
    int y1 = center.y() - R;
    int x2 = 2 * R;
    int y2 = 2* R;

    int startAngle = _startAngle.gr() * 16.;
    int spanAngle = _spanAngle.gr() * 16.;
    //qDebug() << startAngle << spanAngle;
    painter->drawArc(x1, y1, x2,y2,startAngle,spanAngle);
}

void Arc::moving(Point shift, Angle rotation)
{
    _center = _center + shift;
    _spanAngle = _spanAngle + rotation;
    _startAngle = _startAngle + rotation;
}

void Arc::moving(Point localCenter, Point shift, Angle rotation)
{
    Circle::moving(localCenter,shift, rotation);
    _spanAngle = _spanAngle + rotation;
    _startAngle = _startAngle + rotation;
}

Arc *Arc::clone()
{
    return new Arc(*this);
}

bool Arc::rayIntersectionWithACircle(old_Ray ray, Point &point1, Point &point2)
{
    double xc = _center.x();
    double yc = _center.y();
    double alpha = ray.alpha();
    double x0 = ray.x();
    double y0 = ray.y();
    double r = _radius;
    double d = -2 * xc * tan(alpha) *y0
            + 2 * xc * yc * tan(alpha)
            + 2 * xc * pow(tan(alpha),2) * x0
            + pow(tan(alpha),2) * pow(r,2)
            - pow(tan(alpha),2) * pow(xc,2)
            + 2 * y0 * tan(alpha) * x0
            - 2 * tan(alpha) * x0 * yc
            + pow(r, 2)
            - pow(y0, 2) + 2 * y0 * yc
            - pow(tan(alpha),2) * pow(x0,2)
            - pow(yc, 2);
    if (d > 0){
        double a = xc - y0 * tan(alpha) + yc * tan(alpha) +
                pow(tan(alpha),2) *x0;
        double b = pow(tan(alpha), 2) + 1;
        //qDebug() << d << a << b << tan(alpha) << xc << yc << x0 << y0 << r;
        point1.setX((a + sqrt(d)) / b);
        point1.setY(y0 + tan(alpha) * (point1.x() - x0));
        point2.setX((a - sqrt(d)) / b);
        point2.setY(y0 + tan(alpha) * (point2.x() - x0));
        return true;
    }
    else
        return false;
}

bool Arc::pointOnArc(Point point) const
{
    Angle a1, a2, phi;
    phi =  _center.alpha(point).from0to2Pi() - _startAngle;
    if(0 <= phi && phi <= _spanAngle) return true;
    else return false;
}

void Arc::counterClockwise(Angle alpha1, Angle alpha2, Angle alpha)
{
    alpha1.from0to2Pi();
    alpha2.from0to2Pi();
    alpha.from0to2Pi();
    if(alpha1 > alpha2){
        auto tmp = alpha1;
        alpha1 = alpha2;
        alpha2 = tmp;
    }
    Angle a1, a2, a;
    a1 = 0;
    a2 = alpha2 - alpha1;
    a = alpha - alpha1;
    if (a1 < a && a < a2){
        _startAngle = alpha1;
        _spanAngle = a2;
    } else {
        _startAngle = alpha2;
        _spanAngle = 2 * CNST::PI - a2;
    }
}
