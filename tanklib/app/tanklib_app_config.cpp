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

    std::vector<JsonParamPtr> params{
        jsonParam(simpleVertexShaderFiles1,
                  {"shaders", "simpleVertexShaderFiles"},
                  true, k_nonEmptyStrVecV),
        jsonParam(simpleFragShaderFiles1,
                  {"shaders", "simpleFragShaderFiles"},
                  true, k_nonEmptyStrVecV),
    };

    parse(params, doc);

    marshalFileNames(simpleVertexShaderFiles_,
                     simpleVertexShaderFiles1,
                     glslDir_);
    marshalFileNames(simpleFragShaderFiles_,
                     simpleFragShaderFiles1,
                     glslDir_);
}

} // end of namespace tanklib
} // end of namespace mcdane
