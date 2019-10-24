#ifndef NEWRAY_H
#define NEWRAY_H
#include "vector.h"
#include <algorithm>

template <typename T = double, int N = 3>
class Ray
{
public:
    Ray();
    void setVector(const Vector<T, N> &vec);
    //Vector<T, N> &vec();
private:
    Vector<T, N> _vec;
};

#endif // NEWRAY_H
