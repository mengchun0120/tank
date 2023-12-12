#ifndef INCLUDED_TANKLIB_GRAPHICS_H
#define INCLUDED_TANKLIB_GRAPHICS_H

#include <tanklib_simple_shader_program.h>

namespace mcdane {
namespace tanklib {

class AppConfig;

class Graphics {
public:
    Graphics() = default;

    void init(const AppConfig &cfg);

    inline SimpleShaderProgram &simpleShader();

private:
    SimpleShaderProgram simpleShader_;
};

SimpleShaderProgram &Graphics::simpleShader()
{
    return simpleShader_;
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

