#ifndef INCLUDED_TANKLIB_APP_CONFIG_H
#define INCLUDED_TANKLIB_APP_CONFIG_H

#include <string>
#include <vector>
#include <rapidjson/document.h>

namespace mcdane {
namespace tanklib {

struct AppConfig {
public:
    static inline const AppConfig &instance();

    static void init(const std::string &path,
                     const std::string &appDir="");

private:
    AppConfig(const rapidjson::Document &doc,
              const std::string &appDir);

    void loadBasics(const rapidjson::Document &doc);

    void loadDirectories(const rapidjson::Document &doc,
                         const std::string &appDir);

    void loadShaderFiles(const rapidjson::Document &doc);

    void loadLibFiles(const rapidjson::Document &doc);

private:
    static std::shared_ptr<AppConfig> k_instance;

public:
    std::string logFile_;
    unsigned int width_;
    unsigned int height_;
    std::string title_;
    std::string fontDir_;
    std::string picDir_;
    std::string glslDir_;
    std::string configDir_;
    std::string libDir_;
    std::string mapDir_;
    std::vector<std::string> simpleVertexShaderFiles_;
    std::vector<std::string> simpleFragShaderFiles_;
    std::vector<std::string> particleVertexShaderFiles_;
    std::vector<std::string> particleFragShaderFiles_;
    std::string textureLibFile_;
    std::string rectLibFile_;
    std::string iconTemplateLibFile_;
    std::string componentTemplateLibFile_;
    std::string tileTemplateLibFile_;
    std::string particleEffectTemplateLibFile_;
    std::string particleEffectDataDir_;
};

const AppConfig &AppConfig::instance()
{
    return *k_instance;
}

} // end of namespace tanklib
} // end of namespace mcdane


#endif
