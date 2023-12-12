#include <commonlib_log.h>
#include <commonlib_out_utils.h>
#include <commonlib_json_param.h>
#include <commonlib_file_utils.h>
#include <tanklib_app_config.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

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


} // end of namespace tanklib
} // end of namespace mcdane
