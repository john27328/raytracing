#include "old_line_sector.h"

LineSector::LineSector()
{

}

LineSector::LineSector(Point point1, Point point2, Point pointIn, QBrush brush)
{
    _point1 = point1;
    _point2 = point2;
    _pointIn = pointIn;
    _brush = brush;
}

LineSector::~LineSector()
{

}

old_Ray LineSector::intersectionRayLen(const old_Ray &ray) const
{
    /**********************************************************************
    отрезок
    x = x1 + (x2 - x1) * t
    y = y1 + (x2 - x1) * t
    0<=t<=1

    луч
    x = x0 + cos(alpha) * k
    y = y0 + sin(alpha) * k
    k > 0;

    k = -(y0*x2-y0*x1-y1*x2-y2*x0+y2*x1+y1*x0)
        /(-cos(alpha)*y2+cos(alpha)*y1+sin(alpha)*x2-sin(alpha)*x1)
    t = -(sin(alpha)*x1+cos(alpha)*y0-x0*sin(alpha)-cos(alpha)*y1)
        /(-cos(alpha)*y2+cos(alpha)*y1+sin(alpha)*x2-sin(alpha)*x1)
    ***********************************************************************/

    old_Ray newRay = ray;
    if (ray.getEdge()!= this){
        double x0 = ray.x();
        double y0 = ray.y();
        Angle alpha = ray.alpha();
        double x1 = _point1.x();
        double y1 = _point1.y();
        double x2 = _point2.x();
        double y2 = _point2.y();
        //double rayOut;

        double k = -(y0 * x2 - y0 * x1 - y1 * x2 - y2 * x0 + y2 * x1 + y1 * x0)
                / (-cos(alpha) * y2 + cos(alpha) * y1 + sin(alpha) * x2-sin(alpha) * x1);

        double t = -(sin(alpha) * x1 + cos(alpha) * y0 - x0 * sin(alpha) - cos(alpha) * y1)
                /(-cos(alpha) * y2 + cos(alpha) * y1 + sin(alpha) * x2 - sin(alpha) * x1);
        //qDebug() << x0 << y0 << alpha << x1 << y1 << x2 << y2 << t;
        if (k < 0 || t < 0 || t > 1){
            newRay.setLen(-1);
            return newRay;
        } else {
            Point point(x1 + (x2-x1) * t, y1 + (y2-y1) * t);
            double len = point.len(ray.point());
            //qDebug() <<"len" << len << point.x() << point.y() << ray.x() << ray.y();
            newRay.setPoint(point);
            newRay.setLen(len);
            newRay.setNormal(normal(point));
            LineSector *tmp = const_cast<LineSector *>(this);
            newRay.setEdge(tmp);
            return newRay;
        }
    }
    else {
        newRay.setLen(-1);
        return newRay;
    }
}

void LineSector::draw(QPainter *painter, Screen *screen)
{
    painter->drawLine(screen->doubleToInt(_point1), screen->doubleToInt(_point2));
}

Angle LineSector::normal(const Point &point) const
{
    Angle alpha = _point1.alpha(_point2) + CNST::PI / 2.;
    Point tmp{cos(alpha), sin(alpha)};
    if (pointsOnOneSide(_pointIn,tmp))
        alpha = alpha + CNST::PI;
    alpha.fromNPiToPi();
    return alpha;
}

void LineSector::moving(Point shift, Angle rotation)
{
    _point1.rotation(_pointIn, rotation);
    _point2.rotation(_pointIn, rotation);
    _point1 = _point1 + shift;
    _point2 = _point2 + shift;
    _pointIn = _pointIn + shift;
}

void LineSector::moving(Point localCenter, Point shift, Angle rotation)
{
    _point1 = _point1 + shift;
    _point2 = _point2 + shift;
    _pointIn = _pointIn + shift;
    _point1.rotation(localCenter, rotation);
    _point2.rotation(localCenter, rotation);
    _pointIn.rotation(localCenter, rotation);
}

LineSector *LineSector::clone()
{
    return new LineSector(*this);
}

bool LineSector::pointsOnOneSide(const Point &point1, const Point &point2) const
{
    // с какой стороны луч
    //ax + by + c = 0
    //(y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1) = 0
    double x1 = _point1.x();
    double y1 = _point1.y();
    double x2 = _point2.x();
    double y2 = _point2.y();

    double x0 = point1.x();
    double y0 = point1.y();
    double xIn = point2.x();
    double yIn = point2.x();
    double deltaIn = (y1 - y2) * xIn + (x2 - x1) * yIn + (x1 * y2 - x2 * y1);
    double deltaRay = (y1 - y2) * x0 + (x2 - x1) * y0 + (x1 * y2 - x2 * y1);
    if(deltaIn * deltaRay > 0) {
        return true;
    }
    else{
        return false;
    }
}
