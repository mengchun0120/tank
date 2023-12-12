#include <commonlib_exception.h>
#include <commonlib_log.h>
#include <tanklib_app_config.h>
#include <tanklib_context.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

std::shared_ptr<Context> Context::k_instance;

void Context::init(const AppConfig &cfg)
{
    k_instance.reset(new Context(cfg));
}

Context::Context(const AppConfig &cfg)
{
    graphics_.init(cfg);

    LOG_INFO << "Context initialized successfully" << LOG_END;
}

} // end of namespace tanklib
} // end of namespace mcdane

