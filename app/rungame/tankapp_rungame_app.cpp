#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <tanklib_app_config.h>
#include <tankapp_rungame_app.h>

using namespace mcdane::commonlib;
using namespace mcdane::tanklib;

namespace mcdane {
namespace tankapp {

void RunGameApp::init(const std::string &configFile,
                      const std::string &appDir,
                      const std::string &mapFile)
{
    AppConfig::init(configFile, appDir);
    auto &cfg = AppConfig::instance();
    App::init(cfg.width_, cfg.height_, cfg.title_);
}

void RunGameApp::process()
{
    App::process();
    postProcess();
}

bool RunGameApp::operator()(const InputEvent &e)
{
    return true;
}

} // end of namespace tankapp
} // end of namespace mcdane

