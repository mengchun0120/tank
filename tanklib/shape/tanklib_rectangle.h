#ifndef INCLUDED_TANKLIB_RECTANGLE_H
#define INCLUDED_TANKLIB_RECTANGLE_H

#include <ostream>
#include <tanklib_polygon.h>
#include <tanklib_tex_rectangle.h>

namespace mcdane {
namespace tanklib {

class Rectangle: public Polygon {
public:
    Rectangle() = default;

    Rectangle(float width1,
              float height1);

    Rectangle(float width1,
              float height1,
              const TexRectangle &texRect);

    ~Rectangle() override = default;

    void init(const rapidjson::Value &v,
              bool requireName=false);

    void init(float width1,
              float height1);

    void init(float width,
              float height,
              const TexRectangle &texRect);

    float width() const
    {
        return width_;
    }

    float height() const
    {
        return height_;
    }

private:
    float width_, height_;
};

} // end of namespace tanklib
} // end of namespace mcdane

#endif

