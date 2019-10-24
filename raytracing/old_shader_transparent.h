#ifndef SHADERGLASS_H
#define SHADERGLASS_H
#include "old_shader.h"
#include "normal_distribution.h"

class ShaderTransparent: public Shader
{
public:
    ShaderTransparent(ShaderTransparent &shader);
    ShaderTransparent(old_Edge *edge, double refractiveIndexIn, double refractiveIndexOut,
                       double FWHMDeviationOfTheNormal);
    ~ShaderTransparent();
    old_Ray intersectionRayLen(const old_Ray &rayIn) const override;
    ShaderTransparent *clone() override;
private:
    double _refractiveIndexIn;
    double _refractiveIndexOut;
    NormalDistribution *_dis = nullptr;

};

#endif // SHADERGLASS_H
