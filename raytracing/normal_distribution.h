#ifndef NORMALDISTRIBUTION_H
#define NORMALDISTRIBUTION_H
#include "distribution.h"

class NormalDistribution
{
public:
    NormalDistribution(double alpha0, double FWHM);
    ~NormalDistribution();
    double rand();
private:
    GenDistribution gen;
    std::normal_distribution<double> * distribution;
};

#endif // NORMALDISTRIBUTION_H
