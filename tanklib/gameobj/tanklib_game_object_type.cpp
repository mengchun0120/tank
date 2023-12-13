#include <commonlib_exception.h>
#include <tanklib_game_object_type.h>

namespace mcdane {
namespace tanklib {

} // end of namespace tanklib
} // end of namespace mcdane

namespace std {

ostream &operator<<(ostream& os, mcdane::tanklib::GameObjectType t)
{
    using namespace mcdane::tanklib;
    using namespace mcdane::commonlib;

    switch(t)
    {
        case GameObjectType::TILE:
            return os << "tile";
        case GameObjectType::GOODIE:
            return os << "goodie";
        case GameObjectType::ROTANK:
            return os << "robot";
        case GameObjectType::MISSILE:
            return os << "missile";
        case GameObjectType::EFFECT:
            return os << "effect";
        default:
            THROW_EXCEPT(InvalidArgumentException,
                         "Invalid GameObjectType "
                         + std::to_string(static_cast<int>(t)));
    }
}

} // end of namespace std

