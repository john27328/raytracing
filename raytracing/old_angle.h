#ifndef ANGLE_H
#define ANGLE_H

#include "const.h"

class Angle
{
public:
    Angle();
    Angle(double alpha);
    Angle(double alpha, bool grad);
    operator double() const;
    Angle operator+ (Angle beta);
    Angle operator+ (double beta);
    Angle operator- (Angle beta);
    Angle operator- (double beta);
    Angle operator*(Angle beta);
    Angle operator*(double beta);
    Angle from0to2Pi();
    Angle fromNPiToPi();
    double gr();
    static Angle gr(double gr);
private:
    double _angle = 0;
};

long double operator "" _gr(long double grad);

long double operator "" _gr(unsigned long long grad);


#endif // ANGLE_H
