#include <tanklib_tex_pos_array.h>

namespace mcdane {
namespace tanklib {

TexPosArray::TexPosArray(std::initializer_list<commonlib::Point2> texPos)
{
    load(texPos);
}

TexPosArray::TexPosArray(const std::vector<commonlib::Point2> &texPos)
{
    load(texPos);
}

void TexPosArray::load(std::initializer_list<commonlib::Point2> texPos)
{
    load(texPos.begin(), texPos.end());
}

void TexPosArray::load(const std::vector<commonlib::Point2> &texPos)
{
    load(texPos.begin(), texPos.end());
}

} // end of namespace tanklib
} // end of namespace mcdane

