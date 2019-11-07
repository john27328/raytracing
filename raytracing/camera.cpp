#include "camera.h"

template <typename T, int N>
Camera<T, N>::Camera(Vector<T> p0, Vector<T> direction, ScreenSPtr &screen):
    _p0(p0), _direction(direction), _screen(screen)
{

}
