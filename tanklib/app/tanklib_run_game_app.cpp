#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <tanklib_run_game_app.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

void RunGameApp::init(const std::string &configFile,
                      const std::string &appDir,
                      const std::string &mapFile)
{
}

void RunGameApp::process()
{
    App::process();
    postProcess();
}

bool RunGameApp::operator()(const commonlib::InputEvent &e)
{
    return true;
}

} // end of namespace tanklib
} // end of namespace mcdane

