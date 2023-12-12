#ifndef INCLUDED_TANKLIB_RUN_GAME_APP_H
#define INCLUDED_TANKLIB_RUN_GAME_APP_H

#include <commonlib_app.h>
#include <commonlib_input_event.h>

namespace mcdane {
namespace tanklib {

class RunGameApp: public commonlib::App {
public:
    RunGameApp() = default;

    ~RunGameApp() = default;

    void init(const std::string &configFile,
              const std::string &appDir,
              const std::string &mapFile);

    void process() override;

    bool operator()(const commonlib::InputEvent &e);
};

} // end of namespace tanklib
} // end of namespace mcdane

#endif

