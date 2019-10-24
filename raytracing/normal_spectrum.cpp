#include "normal_spectrum.h"

normalSpectrum::normalSpectrum(double lambda_nm)
{
    set(lambda_nm, 0, 0);
}

normalSpectrum::normalSpectrum(double lambda_nm, double FWHM, int N)
{
    set(lambda_nm, FWHM, N);
}

void normalSpectrum::set(double lambda_nm, double FWHM, int N)
{
    _lambda0 = lambda_nm;
    if (N <= 1){
        _lambda_nm.push_back(lambda_nm);
        _power.push_back(1);
    }
    else {
        double sigma = FWHM / (2 * sqrt(2 * log(2)));
        double xMax = 2 * sigma;
        double dx = 2 * xMax / (N - 1);
        for(int i = 0; i < N; i++){
            double x = - 2 * sigma + i * dx;
            _lambda_nm.push_back(lambda_nm + x);
            _power.push_back(gauss(x, sigma));
        }
    }
}

std::vector<double> normalSpectrum::lambda_nm() const
{
    return _lambda_nm;
}

std::vector<double> normalSpectrum::power() const
{
    return _power;
}

double normalSpectrum::gauss(double x, double sigma)
{
    return 1 / (sigma * sqrt(2*CNST::PI))
            * exp(-pow(x,2) / (2 * pow(sigma,2)));
}
