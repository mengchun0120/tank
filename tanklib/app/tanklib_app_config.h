#ifndef INCLUDED_TANKLIB_APP_CONFIG_H
#define INCLUDED_TANKLIB_APP_CONFIG_H

#include <string>
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

private:
    static std::shared_ptr<AppConfig> k_instance;

public:
    std::string logFile_;
    unsigned int width_;
    unsigned int height_;
    std::string title_;
};

const AppConfig &AppConfig::instance()
{
    return *k_instance;
}

} // end of namespace tanklib
} // end of namespace mcdane


#endif