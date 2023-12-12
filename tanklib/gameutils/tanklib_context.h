#ifndef INCLUDED_TANKLIB_CONTEXT_H
#define INCLUDED_TANKLIB_CONTEXT_H

#include <memory>
#include <tanklib_graphics.h>

namespace mcdane {
namespace tanklib {

class AppConfig;

class Context {
public:
    static void init(const AppConfig &cfg);

    inline static Graphics &graphics();

private:
    Context(const AppConfig &cfg);

private:
    static std::shared_ptr<Context> k_instance;
    Graphics graphics_;
};

Graphics &Context::graphics()
{
    return k_instance->graphics_;
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

