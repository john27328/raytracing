#include "uniform_int_distribution.h"



UniformIntDistribution::UniformIntDistribution(int i1, int in)
{

    dis = new std::uniform_int_distribution<int>(i1,in);
}

UniformIntDistribution::~UniformIntDistribution()
{
    delete dis;
}

int UniformIntDistribution::rand()
{
    if(dis){
        return (*dis)(gen());
    }
    return 0;
}
