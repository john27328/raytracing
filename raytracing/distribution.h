#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#include <random>
#include <math.h>
#include <QDebug>

class GenDistribution
{
public:
    GenDistribution();
    ~GenDistribution();
    std::mt19937 &operator()();
protected:
    static std::mt19937 *gen;
    static int n;
};

#endif // DISTRIBUTION_H
