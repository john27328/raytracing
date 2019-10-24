#include "distribution.h"

int GenDistribution::n = 0;
std::mt19937 *GenDistribution::gen = nullptr;

GenDistribution::GenDistribution()
{
    n++;
    if(!gen) {
        std::random_device rd;
        gen = new std::mt19937(rd());
//        qDebug() << "new mt19937";
    }
}

GenDistribution::~GenDistribution()
{
    n--;
    if(n == 0)
    {
        delete  gen; gen = nullptr;
//        qDebug() << "delete mt19937";

    }
}

std::mt19937 &GenDistribution::operator()()
{
    return *gen;
}

