#include "old_shader_mirror.h"


ShaderMirror::ShaderMirror()
{

}

ShaderMirror::ShaderMirror(old_Edge *edge):
    Shader(edge)
{
}

ShaderMirror::ShaderMirror(ShaderMirror const &shader)
{
    if (shader._edge)
        _edge = shader._edge->clone();
}

old_Ray ShaderMirror::intersectionRayLen(const old_Ray &rayIn) const
{
    // sin(alpha) / sin(beta) = n2 / n1 = n; alpha = theta1, beta = theta2
    if (!_edge) {
        old_Ray tmp;
        return tmp;
    }
    old_Ray newRay = _edge->intersectionRayLen(rayIn);
    Angle gamma = newRay.getNormal(); // угол нормали.
    Angle alpha1l = newRay.alpha() - gamma;
//    qDebug() << alpha1l;
    Angle alpha2l = CNST::PI - alpha1l;
    //угол падяющего луча
    Angle alpha2 = gamma + alpha2l;
    alpha2.from0to2Pi();
    newRay.setAlpha(alpha2);
    return newRay;
}

ShaderMirror *ShaderMirror::clone()
{
    return new ShaderMirror(*this);
}

