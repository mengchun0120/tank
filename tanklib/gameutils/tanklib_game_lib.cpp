#include <commonlib_log.h>
#include <commonlib_json_param.h>
#include <commonlib_file_utils.h>
#include <tanklib_app_config.h>
#include <tanklib_constants.h>
#include <tanklib_game_lib.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

void GameLib::init(const AppConfig &cfg)
{
    initTextureLib(cfg.textureLibFile_, cfg.picDir_);
    initRectLib(cfg.rectLibFile_);
    initIconTemplateLib(cfg.iconTemplateLibFile_);
    initComponentTemplateLib(cfg.componentTemplateLibFile_);
    initTileTemplateLib(cfg.tileTemplateLibFile_);
    initParticleEffectTemplateLib(cfg.particleEffectTemplateLibFile_,
                                  cfg.particleEffectDataDir_);

    calculateMaxObjSpan();
    calculateMaxCollideBreath();
    calculateMaxTouchSpan();

    LOG_INFO << "GameLib loaded successfull" << LOG_END;
}

void GameLib::initTextureLib(const std::string &textureLibFile,
                             const std::string &picDir)
{
    auto parser = [&](Texture &texture,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        texture.init(v, picDir);
    };

    textureLib_.init(textureLibFile, parser);

    LOG_DEBUG << "textureLib loaded successfully" << LOG_END;
}

void GameLib::initRectLib(const std::string &rectLibFile)
{
    auto parser = [&](Rectangle &rect,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        rect.init(v, true);
    };

    rectLib_.init(rectLibFile, parser);

    LOG_DEBUG << "rectLib loaded successfully" << LOG_END;
}

void GameLib::initIconTemplateLib(const std::string &iconTemplateLibFile)
{
    auto parser = [&](IconTemplate &t,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        t.init(v, textureLib_, rectLib_);
    };

    iconTemplateLib_.init(iconTemplateLibFile, parser);

    LOG_DEBUG << "iconTemplateLib loaded successfully" << LOG_END;
}

void GameLib::initComponentTemplateLib(
                    const std::string &componentTemplateLibFile)
{
    auto parser = [&](ComponentTemplate &t,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        t.init(v, iconTemplateLib_);
    };

    componentTemplateLib_.init(componentTemplateLibFile, parser);

    LOG_DEBUG << "componentTemplateLib loaded successfully" << LOG_END;
}

void GameLib::initTileTemplateLib(const std::string &tileTemplateLibFile)
{
    auto parser = [&](TileTemplate &t,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        t.init(name, v, componentTemplateLib_);
    };

    tileTemplateLib_.init(tileTemplateLibFile, parser);

    LOG_DEBUG << "tileTemplateLib loaded successfully" << LOG_END;
}

void GameLib::initParticleEffectTemplateLib(
    const std::string &particleEffectTemplateLibFile,
    const std::string &dataDir)
{
    auto parser = [&](ParticleEffectTemplate &t,
                      const std::string &name,
                      const rapidjson::Value &v)
    {
        t.init(name, v, textureLib_, dataDir);
    };

    particleEffectTemplateLib_.init(particleEffectTemplateLibFile, parser);

    LOG_DEBUG << "particleEffectTemplateLib loaded successfully" << LOG_END;
}

void GameLib::calculateMaxObjSpan()
{
}

void GameLib::calculateMaxCollideBreath()
{
}

void GameLib::calculateMaxTouchSpan()
{
}

} // end of namespace tanklib
} // end of namespace mcdane

