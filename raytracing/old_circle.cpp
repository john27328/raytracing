#include "old_circle.h"

//Circle::Circle(Point center), double r, QBrush brush)
//{
//    _center = center;
//    _brush = brush;
//    _radius = r;
//}

Circle::Circle(double x, double y, double r, QBrush brush)
{
    _center = {x,y};
    _radius = r;
    _brush = brush;
}

Circle::Circle(Point center, double r, QBrush brush)
{
    _center = center;
    _radius = r;
    _brush = brush;
}


old_Ray Circle::intersectionRayLen(const old_Ray &ray) const // с
{
    // sin(alpha) / sin(beta) = n2 / n1 = n;
    Point point; // точка пересечения
    double len = -1;
    //qDebug() << "ray" << ray.x() << ray.y() << ray.alpha();
    Point point1, point2;
    old_Ray newRay = ray;
    if (rayIntersectionWithACircle(ray, point1, point2)){
        double len1 = ray.pPoint()->len(point1);
        double len2 = ray.pPoint()->len(point2);
        if(ray.getEdge() != this)//луч не на кривой
        {
            if (ray.pointOnRay(point1) && ray.pointOnRay(point2)) {
                //qDebug() <<"    не на кривой 2 точки пересечения - луч снаружи";
                if (len1 < len2) {
                    point = point1;
                    len = len1;
                }
                else {
                    point = point2;
                    len = len2;
                }
            }
            if (ray.pointOnRay(point1) && !ray.pointOnRay(point2)){
                //qDebug() << "   не на кривой 1 точка пересечения - луч изнутри";
                point = point1;
                len = len1;
            }
            if (!ray.pointOnRay(point1) && ray.pointOnRay(point2)){
                //qDebug() << "   не на кривой 1 точка пересечения - луч изнутри";
                point = point2;
                len = len2;
            }
        }
        else{
            //qDebug() << "   луч на кривой, 1 точка - луч изнутри";
            if(len1 > len2 && ray.pointOnRay(point1)) {
                point = point1;
                len = len1;
            }
            if (len2 > len1 && ray.pointOnRay(point2)){
                point = point2;
                len = len2;
            }
        }

    }

        newRay.setPoint(point);
        newRay.setLen(len);
        newRay.setAlpha(ray.alpha());
        newRay.setNormal(normal(point));
        Circle *tmp = const_cast<Circle *>(this);
        newRay.setEdge(tmp);
        return newRay;
}

void Circle::draw(QPainter *painter, Screen *screen)
{
    QPoint center = screen->doubleToInt(_center);
    int R = _radius / screen->range().x() * screen->resolutionX();
//    qDebug() << "drow circle " << center.x() << center.y() << R;
    painter->drawEllipse(center,R,R);
}

Angle Circle::normal(const Point &point) const
{
    return _center.alpha(point);
}

void Circle::moving(Point shift, Angle rotation)
{
    _center = _center + shift;
}

void Circle::moving(Point localCenter, Point shift, Angle rotation)
{
    _center.rotation(localCenter, rotation);
    _center = _center + shift;
}

Circle *Circle::clone()
{
    return new Circle(*this);
}


bool Circle::rayIntersectionWithACircle(old_Ray ray, Point &point1, Point &point2) const
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


