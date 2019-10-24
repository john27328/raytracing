#ifndef NEWRAY_H
#define NEWRAY_H
#include "vector.h"
#include <algorithm>
#include "edge.h"

template <typename T = double, int N = 3>
class Ray
{
public:
    Ray();
    void setVector(const Vector<T, N> &point, const Vector<T, N> &vec);
    T traseLen(EdgeList<T, N> &list);
    //Vector<T, N> &vec();
private:
    Vector<T, N> _point;
    Vector<T, N> _vec;
};

template <typename T, int N>
using vectorSPtr = std::shared_ptr<Vector<T, N>>;
#endif // NEWRAY_H
