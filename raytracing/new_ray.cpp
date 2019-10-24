#include "ray.h"

template <typename T, int N>
Ray<T, N>::Ray()
{

}

template<typename T, int N>
void Ray<T, N>::setVector(const Vector<T, N> &vec)
{
    T r = vec.len();
    for (int i = 0; i < N; i++){
        _vec[i] = vec[i] / r;
    }
}
