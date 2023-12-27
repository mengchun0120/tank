#ifndef INCLUDED_TANKLIB_CONTEXT_H
#define INCLUDED_TANKLIB_CONTEXT_H

#include <memory>
#include <tanklib_graphics.h>
#include <tanklib_game_lib.h>

namespace mcdane {
namespace tanklib {

class AppConfig;

class Context {
public:
    static void init(const AppConfig &cfg);

    inline static Graphics &graphics();

    inline static const GameLib &gameLib();

private:
    Context(const AppConfig &cfg);

private:
    static std::shared_ptr<Context> k_instance;
    Graphics graphics_;
    GameLib gameLib_;
};

Graphics &Context::graphics()
{
    return k_instance->graphics_;
}

const GameLib &Context::gameLib()
{
    return k_instance->gameLib_;
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

