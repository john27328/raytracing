#include "uniform_real_distribution.h"

UniformRealDistribution::UniformRealDistribution(double i1, double in)
{
    dis = new std::uniform_real_distribution<double>(i1,in);
}

UniformRealDistribution::~UniformRealDistribution()
{
    delete dis;
}

double UniformRealDistribution::rand()
{
    if(dis){
        return (*dis)(gen());
    }
}
