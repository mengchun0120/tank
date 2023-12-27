#ifndef INCLUDED_TANKLIB_ICON_TEMPLATE_H
#define INCLUDED_TANKLIB_ICON_TEMPLATE_H

#include <rapidjson/document.h>
#include <tanklib_typedef.h>

namespace mcdane {
namespace tanklib {

class IconTemplate {
public:
    IconTemplate() = default;

    void init(const rapidjson::Value &v,
              const TextureLib &textureLib,
              const RectLib &rectLib);

    inline const commonlib::Texture *texture() const;

    inline const Rectangle *rect() const;

private:
    const commonlib::Texture *texture_;
    const Rectangle *rect_;
};

const commonlib::Texture *IconTemplate::texture() const
{
    return texture_;
}

const Rectangle *IconTemplate::rect() const
{
    return rect_;
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

