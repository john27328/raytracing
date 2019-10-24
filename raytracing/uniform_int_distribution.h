#ifndef UNIFORMIINTDISTRIBUTION_H
#define UNIFORMIINTDISTRIBUTION_H
#include "distribution.h"

class UniformIntDistribution
{
public:
    UniformIntDistribution(int i1, int in);
    ~UniformIntDistribution();
    int rand();
private:
    std::uniform_int_distribution<> * dis = nullptr;
    GenDistribution gen;
};

#endif // UNIFORMIINTDISTRIBUTION_H
