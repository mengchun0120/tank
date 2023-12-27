#ifndef INLCUDED_TANKLIB_GAME_LIB_H
#define INLCUDED_TANKLIB_GAME_LIB_H

#include <commonlib_named_map.h>
#include <commonlib_texture.h>
#include <commonlib_vertex_array.h>
#include <tanklib_rectangle.h>
#include <tanklib_component_template.h>
#include <tanklib_tile_template.h>
#include <tanklib_particle_effect_template.h>
#include <tanklib_typedef.h>

namespace mcdane {
namespace tanklib {

class AppConfig;

class GameLib {
public:
    GameLib() = default;

    void init(const AppConfig &cfg);

private:
    void initTextureLib(const std::string &textureLibFile,
                        const std::string &picDir);

    void initRectLib(const std::string &rectLibFile);

    void initIconTemplateLib(const std::string &iconTemplateLibFile);

    void initComponentTemplateLib(const std::string &componentTemplateLibFile);

    void initTileTemplateLib(const std::string &tileTemplateLibFile);

    void initParticleEffectTemplateLib(
        const std::string &particleEffectTemplateLibFile,
        const std::string &dataDir);

    void calculateMaxObjSpan();

    void calculateMaxCollideBreath();

    void calculateMaxTouchSpan();

public:
    TextureLib textureLib_;
    RectLib rectLib_;
    IconTemplateLib iconTemplateLib_;
    ComponentTemplateLib componentTemplateLib_;
    TileTemplateLib tileTemplateLib_;
    ParticleEffectTemplateLib particleEffectTemplateLib_;
    float maxObjSpan_;
    float maxCollideBreath_;
    float maxTouchSpan_;
};

} // end of namespace tanklib
} // end of namespace mcdane

#endif

