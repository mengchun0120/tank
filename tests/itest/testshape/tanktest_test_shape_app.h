#ifndef INCLUDED_TANKTEST_TEST_SHAPE_APP_H
#define INCLUDED_TANKTEST_TEST_SHAPE_APP_H

#include <commonlib_app.h>
#include <commonlib_color.h>
#include <commonlib_texture.h>
#include <tanklib_rectangle.h>

namespace mcdane {
namespace tanktest {

class TestShapeApp: public commonlib::App {
public:
    TestShapeApp();

    void init(const std::string &configFile,
              const std::string &appDir);

    ~TestShapeApp() override = default;

    void process() override;

protected:
    void setupShader();

    void setupShapeColor();

    void setupTexture();

    void onViewportChange(float width1, float height1) override;

private:
    tanklib::Polygon triangle_;
    tanklib::Rectangle square_;
    commonlib::Point2 trianglePos_;
    commonlib::Point2 squarePos_;
    commonlib::Color fillColor_;
    commonlib::Color borderColor_;
    commonlib::Texture texture_;
    tanklib::Rectangle texRect_;
    commonlib::Point2 texPos_;
};

} // end of namespace tanktest
} // end of namespace mcdane

#endif

