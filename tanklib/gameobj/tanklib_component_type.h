#ifndef INCLUDED_TANKLIB_COMPONENT_TYPE_H
#define INCLUDED_TANKLIB_COMPONENT_TYPE_H

#include <string>

namespace mcdane {
namespace tanklib {

enum class ComponentType {
    TILE,
    BASE,
    GUN,
    MISSILE,
    GOODIE
};

constexpr int COMPONENT_TYPE_COUNT = 5;

const std::string &toString(ComponentType type);

ComponentType toComponentType(const std::string &typeStr);

} // end of namespace tanklib
} // end of namespace mcdane

#endif
