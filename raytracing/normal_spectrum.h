#ifndef NORMALIZESPECTRUM_H
#define NORMALIZESPECTRUM_H

#include <vector>
#include <math.h>
#include <const.h>
class normalSpectrum
{
public:
    normalSpectrum(double lambda_nm);
    normalSpectrum(double lambda_nm, double FWHM, int N);
    void set(double lambda_nm, double FWHM, int N);
    std::vector<double> lambda_nm() const;

    std::vector<double> power() const;

private:
    std::vector<double> _lambda_nm;
    std::vector<double>  _power;
    double _lambda0;
//    int _n;
//    double _sigma;
    double gauss(double x, double sigma);
};

#endif // NORMALIZESPECTRUM_H
