#ifndef CAMERA_H
#define CAMERA_H
#include "vector.h"
#include "screen.h"
#include "edge.h"

template <typename T, int N>
class Camera: public Edge<T, N>
{
public:
    Camera(Vector<T> p0, Vector<T> direction, ScreenSPtr &screen);

private:
    Vector<T> _p0;
    Vector<T> _direction;
    T _fullAbgle;
    ScreenSPtr _screen;

};

#endif // CAMERA_H
