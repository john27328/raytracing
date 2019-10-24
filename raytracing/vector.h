#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

template<typename T = double, int N = 3>
class Vector
{
public:
    Vector();
    T &operator[](int i);
    T len() const;
    T operator *(Vector<T, N> vec2);
    Vector<T, N>  vProd(Vector<T, N> vec2);
private:
    T _mas[N];
};

#endif // VECTOR_H
