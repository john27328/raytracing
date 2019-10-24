#include "normal_distribution.h"

NormalDistribution::NormalDistribution(double alpha0, double FWHM)
{
    //FWHM = 2 * sqrt(2 * ln(2)) * sigma
    double sigma = FWHM / (2 * sqrt(2 * log(2)));
    distribution = new std::normal_distribution<double>(alpha0, sigma);
}

NormalDistribution::~NormalDistribution()
{
    delete distribution;
}

double NormalDistribution::rand()
{
    return (*distribution)(gen());
}
