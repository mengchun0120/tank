#ifndef INCLUDED_TANKLIB_CONSTANTS_H
#define INCLUDED_TANKLIB_CONSTANTS_H

namespace mcdane {
namespace tanklib {

struct Constants {
    static constexpr unsigned int FLOATS_PER_POS = 2;
    static constexpr unsigned int FLOATS_PER_TEXPOS = 2;
    static constexpr unsigned int FLOATS_PER_DIRECTION = 2;
    static constexpr unsigned int POS_SIZE = FLOATS_PER_POS * sizeof(float);
    static constexpr unsigned int TEXPOS_SIZE = FLOATS_PER_TEXPOS * sizeof(float);
    static constexpr unsigned int DIRECTION_SIZE = FLOATS_PER_DIRECTION * sizeof(float);
};

} // end of namespace tanklib
} // end of namespace mcdane

#endif

