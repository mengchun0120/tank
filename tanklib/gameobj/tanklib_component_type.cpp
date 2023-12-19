#include <commonlib_exception.h>
#include <tanklib_component_type.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

const std::string k_componentTypeStr[] = {
    "tile",
    "base",
    "gun",
    "missile",
    "goodie"
};

const std::string &toString(ComponentType type)
{
    return k_componentTypeStr[static_cast<int>(type)];
}

ComponentType toComponentType(const std::string &typeStr)
{
    int i = 0;
    for (; i < COMPONENT_TYPE_COUNT; ++i)
    {
        if (k_componentTypeStr[i] == typeStr)
        {
            return static_cast<ComponentType>(i);
        }
    }

    THROW_EXCEPT(InvalidArgumentException, "Invalid type " + typeStr);
}

} // end of namespace tanklib
} // end of namespace mcdane
