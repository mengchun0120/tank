#include <commonlib_log.h>
#include <tanklib_app_config.h>
#include <tanklib_graphics.h>

namespace mcdane {
namespace tanklib {

void Graphics::init(const AppConfig &cfg)
{
    simpleShader_.init(cfg.simpleVertexShaderFiles_,
                       cfg.simpleFragShaderFiles_);
    particleShader_.init(cfg.particleVertexShaderFiles_,
                         cfg.particleFragShaderFiles_);
    textSys_.init(cfg.fontDir_);

    LOG_INFO << "Graphics created successfully" << LOG_END;
}

} // end of namespace tanklib
} // end of namespace mcdane

