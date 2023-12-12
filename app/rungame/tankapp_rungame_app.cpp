#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <tankapp_rungame_app.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tankapp {

void RunGameApp::init(const std::string &configFile,
                      const std::string &appDir,
                      const std::string &mapFile)
{
    App::init(1000, 800, "Tank battle");
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

