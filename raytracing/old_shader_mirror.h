#ifndef SHADERMIRROR_H
#define SHADERMIRROR_H
#include "old_shader.h"

class ShaderMirror: public Shader
{
public:
    ShaderMirror();
    ShaderMirror(old_Edge *edge);
    ShaderMirror(const ShaderMirror &shader);
    old_Ray intersectionRayLen(const old_Ray &rayIn) const override;
    ShaderMirror *clone() override;
};

#endif // SHADERMIRROR_H
