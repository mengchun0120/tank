#include <commonlib_log.h>
#include <commonlib_out_utils.h>
#include <commonlib_json_param.h>
#include <commonlib_file_utils.h>
#include <tanklib_app_config.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

void marshalFileNames(std::vector<std::string> &newFileNames,
                      const std::vector<std::string> &oldFileNames,
                      const std::string &folder)
{
    newFileNames.resize(oldFileNames.size());
    for (std::size_t i = 0; i < newFileNames.size(); ++i)
    {
        newFileNames[i] = constructPath({folder, oldFileNames[i]});
    }
}

std::shared_ptr<AppConfig> AppConfig::k_instance;

void AppConfig::init(const std::string &path,
                     const std::string &appDir)
{
    if (k_instance)
    {
        LOG_WARN << "AppConfig instance already initialized" << LOG_END;
        return;
    }

    rapidjson::Document doc;
    std::string docPath = constructPath({appDir, path});

    readJson(doc, docPath);

    k_instance.reset(new AppConfig(doc, appDir));
}


AppConfig::AppConfig(const rapidjson::Document &doc,
                     const std::string &appDir)
{
    loadBasics(doc);
    loadDirectories(doc, appDir);
    loadShaderFiles(doc);
    loadLibFiles(doc);

    LOG_INFO << "AppConfig initialized successfully" << LOG_END;
}

void AppConfig::loadBasics(const rapidjson::Document &doc)
{
    std::vector<JsonParamPtr> params{
        jsonParam(width_, {"window", "width"}, true, gt(0u)),
        jsonParam(height_, {"window", "height"}, true, gt(0u)),
        jsonParam(title_, {"window", "title"}, true, k_nonEmptyStrV),
    };

    parse(params, doc);
}

void AppConfig::loadDirectories(const rapidjson::Document &doc,
                                const std::string &appDir)
{
    std::vector<std::string> fontDir, picDir, glslDir, configDir, libDir, mapDir;
    std::vector<JsonParamPtr> params{
        jsonParam(fontDir, {"directories", "fontDir"}, true, k_nonEmptyStrVecV),
        jsonParam(picDir, {"directories", "picDir"}, true, k_nonEmptyStrVecV),
        jsonParam(glslDir, {"directories", "glslDir"}, true, k_nonEmptyStrVecV),
        jsonParam(configDir, {"directories", "configDir"}, true, k_nonEmptyStrVecV),
        jsonParam(libDir, {"directories", "libDir"}, true, k_nonEmptyStrVecV),
        jsonParam(mapDir, {"directories", "mapDir"}, true, k_nonEmptyStrVecV)
    };

    parse(params, doc);

    fontDir_ = constructPath(appDir, fontDir);
    picDir_ = constructPath(appDir, picDir);
    glslDir_ = constructPath(appDir, glslDir);
    configDir_ = constructPath(appDir, configDir);
    libDir_ = constructPath(appDir, libDir);
    mapDir_ = constructPath(appDir, mapDir);
}

void AppConfig::loadShaderFiles(const rapidjson::Document &doc)
{
    std::vector<std::string> simpleVertexShaderFiles1;
    std::vector<std::string> simpleFragShaderFiles1;
    std::vector<std::string> particleVertexShaderFiles1;
    std::vector<std::string> particleFragShaderFiles1;

    std::vector<JsonParamPtr> params{
        jsonParam(simpleVertexShaderFiles1,
                  {"shaders", "simpleVertexShaderFiles"},
                  true, k_nonEmptyStrVecV),
        jsonParam(simpleFragShaderFiles1,
                  {"shaders", "simpleFragShaderFiles"},
                  true, k_nonEmptyStrVecV),
        jsonParam(particleVertexShaderFiles1,
                  {"shaders", "particleVertexShaderFiles"},
                  true, k_nonEmptyStrVecV),
        jsonParam(particleFragShaderFiles1,
                  {"shaders", "particleFragShaderFiles"},
                  true, k_nonEmptyStrVecV),
    };

    parse(params, doc);

    marshalFileNames(simpleVertexShaderFiles_,
                     simpleVertexShaderFiles1,
                     glslDir_);
    marshalFileNames(simpleFragShaderFiles_,
                     simpleFragShaderFiles1,
                     glslDir_);
    marshalFileNames(particleVertexShaderFiles_,
                     particleVertexShaderFiles1,
                     glslDir_);
    marshalFileNames(particleFragShaderFiles_,
                     particleFragShaderFiles1,
                     glslDir_);
}

void AppConfig::loadLibFiles(const rapidjson::Document &doc)
{
    std::vector<JsonParamPtr> params{
        jsonParam(textureLibFile_, {"libraries", "textureLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(rectLibFile_, {"libraries", "rectLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(iconTemplateLibFile_, {"libraries", "iconTemplateLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(componentTemplateLibFile_,
                  {"libraries", "componentTemplateLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(tileTemplateLibFile_, {"libraries", "tileTemplateLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(particleEffectTemplateLibFile_,
                  {"libraries", "particleEffectTemplateLibFile"},
                  true, k_nonEmptyStrV),
        jsonParam(particleEffectDataDir_, {"libraries", "particleEffectDataDir"},
                  true, k_nonEmptyStrV),
    };

    parse(params, doc);

    textureLibFile_ = constructPath({libDir_, textureLibFile_});
    rectLibFile_ = constructPath({libDir_, rectLibFile_});
    iconTemplateLibFile_ = constructPath({libDir_, iconTemplateLibFile_});
    componentTemplateLibFile_ = constructPath({libDir_, componentTemplateLibFile_});
    tileTemplateLibFile_ = constructPath({libDir_, tileTemplateLibFile_});
    particleEffectTemplateLibFile_ = constructPath(
                                     {libDir_, particleEffectTemplateLibFile_});
    particleEffectDataDir_ = constructPath({libDir_, particleEffectDataDir_});
}

} // end of namespace tanklib
} // end of namespace mcdane
