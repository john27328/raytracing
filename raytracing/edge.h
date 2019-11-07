#ifndef EDGE_H
#define EDGE_H
#include "ray.h"
#include "vector.h"
#include <memory>
#include <vector>

template <typename T, int N>
class Edge
{
public:
    Edge();
    virtual ~Edge();
    virtual double intersectionRayLen(const Vector<T, N> &point,
                                            const Vector<T, N> &vec, Vector<T, N> &out) const = 0;
    virtual void moving(Vector<T, N> shift, Vector<T, N> rotationXYZ) = 0;
    virtual void clone() const = 0;

};

template <typename T, int N>
using EdgeSPtr = std::shared_ptr<Edge<T, N>>;

template <typename T, int N>
using EdgeList = std::vector<EdgeSPtr<T, N>>;

#endif // EDGE_H
