#ifndef UNIFORMREALDISTRIBUTION_H
#define UNIFORMREALDISTRIBUTION_H
#include "distribution.h"

class UniformRealDistribution
{
public:
    UniformRealDistribution(double i1, double in);
    ~UniformRealDistribution();
    double rand();
private:
    std::uniform_real_distribution<> * dis = nullptr;
    GenDistribution gen;
};

#endif // UNIFORMREALDISTRIBUTION_H
