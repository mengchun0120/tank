#ifndef INCLUDED_TANKLIB_GRAPHICS_H
#define INCLUDED_TANKLIB_GRAPHICS_H

#include <tanklib_simple_shader_program.h>
#include <tanklib_particle_shader_program.h>
#include <tanklib_text_system.h>

namespace mcdane {
namespace tanklib {

class AppConfig;

class Graphics {
public:
    Graphics() = default;

    void init(const AppConfig &cfg);

    inline SimpleShaderProgram &simpleShader();

    inline ParticleShaderProgram &particleShader();

    inline const TextSystem &textSys() const;

private:
    SimpleShaderProgram simpleShader_;
    ParticleShaderProgram particleShader_;
    TextSystem textSys_;
};

SimpleShaderProgram &Graphics::simpleShader()
{
    return simpleShader_;
}

ParticleShaderProgram &Graphics::particleShader()
{
    return particleShader_;
}

const TextSystem &Graphics::textSys() const
{
    return textSys_;
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

