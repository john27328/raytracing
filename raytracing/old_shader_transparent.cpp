#include "old_shader_transparent.h"

ShaderTransparent::ShaderTransparent(ShaderTransparent &shader):
    _refractiveIndexIn(shader._refractiveIndexIn),
    _refractiveIndexOut(shader._refractiveIndexOut)
{
    if (shader._edge)
        _edge = shader._edge->clone();
    if (shader._dis)
        _dis = new NormalDistribution(*shader._dis);
}

ShaderTransparent ::ShaderTransparent (Edge *edge,
                                       double refractiveIndexIn, double refractiveIndexOut,
                                       double FWHMDeviationOfTheNormal):
    Shader(edge),
    _refractiveIndexIn(refractiveIndexIn),
    _refractiveIndexOut(refractiveIndexOut)
{
    if(FWHMDeviationOfTheNormal >= 0.01_gr)
        _dis = new NormalDistribution(0, FWHMDeviationOfTheNormal);
}

ShaderTransparent::~ShaderTransparent()
{
    if (_dis)
        delete _dis;
}

old_Ray ShaderTransparent ::intersectionRayLen(const old_Ray &rayIn) const
{
    old_Ray newRay = _edge->intersectionRayLen(rayIn);
    Angle gamma = newRay.getNormal(); // угол нормали.
    if(_dis) gamma = gamma + _dis->rand();
    // направление луча
    Angle dAlpha = (rayIn.alpha() - gamma).fromNPiToPi();
    double n = (dAlpha < CNST::PI / 2. && dAlpha > - CNST::PI / 2)
            ? _refractiveIndexOut / _refractiveIndexIn
            : _refractiveIndexIn / _refractiveIndexOut;
    // sin(alpha) / sin(beta) = n2 / n1 = n; alpha = theta1, beta = theta2
    //угол нормали
    //alpha = (-180,180)
    //gamma = (-180,180)

    Angle alpha1l = newRay.alpha() - gamma;
    alpha1l.from0to2Pi();
//    qDebug() << alpha1l;
    Angle alpha2l = 0;
    //угол падяющего луча
    Angle alpha2 = 0;
    //qDebug() <<"        " << n << asin(n) <<  fabs(theta1) << _isMirror<<_radius;
    Angle theta1;
    if(alpha1l >= 0 && alpha1l < CNST::PI / 2.)
        theta1 = alpha1l;
    else if(alpha1l >= CNST::PI / 2. && alpha1l < CNST::PI)
        theta1 = CNST::PI - alpha1l;
    else if(alpha1l >= CNST::PI && alpha1l < 3. / 2. * CNST::PI)
        theta1 = alpha1l - CNST::PI;
    else if(alpha1l >= 3. / 2. * CNST::PI && alpha1l < 2 * CNST::PI)
        theta1 = 2 * CNST::PI - alpha1l;
    Angle theta2 = fabs(asin(sin(theta1) / n));

    if (n > 1 || theta1 < asin(n)){
        if(alpha1l >= 0 && alpha1l < CNST::PI / 2.)
            alpha2l = theta2;
        if(alpha1l >= CNST::PI / 2. && alpha1l < CNST::PI)
            alpha2l = CNST::PI - theta2;
        if(alpha1l >= CNST::PI && alpha1l < 3. / 2. * CNST::PI)
            alpha2l = CNST::PI + theta2;
        if(alpha1l >= 3. / 2. * CNST::PI && alpha1l < 2 * CNST::PI)
            alpha2l = - theta2;
    } else {
        //                        qDebug() <<"pvo";
        alpha2l = CNST::PI - alpha1l;
    }
    alpha2 =  gamma + alpha2l ;

    alpha2.from0to2Pi();
    //    qDebug() << ray.x() << ray.y() << ray.alpha() * 180 / CONST::PI
//             << alpha2 * 180 / CONST::PI << n <<"|"
//             << point.x() << point.y() << "|"<< gamma * 180 / CONST::PI
//             << theta1 * 180 / CONST::PI << theta2 * 180 / CONST::PI;
    newRay.setAlpha(alpha2);
    return newRay;
}

ShaderTransparent *ShaderTransparent::clone()
{
    return new ShaderTransparent(*this);
}
