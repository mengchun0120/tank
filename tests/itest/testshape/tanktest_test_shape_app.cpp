#include <vector>
#include <commonlib_file_utils.h>
#include <tanklib_app_config.h>
#include <tanklib_context.h>
#include <tanktest_test_shape_app.h>

using namespace mcdane::commonlib;
using namespace mcdane::tanklib;

namespace mcdane {
namespace tanktest {

TestShapeApp::TestShapeApp()
    : App("testshape")
{
}

void TestShapeApp::init(const std::string &configFile,
                        const std::string &appDir)
{
    AppConfig::init(configFile, appDir);
    App::init(1000, 800, "Test Shape");
    Context::init(AppConfig::instance());
    setupShader();
    setupShapeColor();
    setupTexture();
}

void TestShapeApp::setupShader()
{
    Point2 viewportOrigin{viewportWidth() / 2.0f, viewportHeight() / 2.0f};
    SimpleShaderProgram &program = Context::graphics().simpleShader();

    program.use();
    program.setViewportSize(viewportSize());
    program.setViewportOrigin(viewportOrigin);
}

void TestShapeApp::setupShapeColor()
{
    triangle_.init({
        Point2{0.0f, 0.0f},
        Point2{0.0f, 100.0f},
        Point2{-100.0f, -50.0f},
        Point2{100.0f, -50.0f},
        Point2{0.0f, 100.0f}
    });

    square_.init(100.0f, 100.0f);

    trianglePos_.init({200.0f, 200.0f});
    squarePos_.init({600.0f, 800.0f});

    fillColor_.init({255, 125, 0, 255});
    borderColor_.init({0, 0, 100, 255});
}

void TestShapeApp::setupTexture()
{
    const AppConfig &cfg = AppConfig::instance();
    std::string imageFile = constructPath({cfg.picDir_, "baby.png"});
    texture_.init(imageFile);

    float w = static_cast<float>(texture_.width()) / 4.0f;

    texRect_.init(100.0f, 100.0f, TexRectangle());
    texPos_.init({w, 300.0});
}

void TestShapeApp::process()
{
    App::process();

    Graphics &g = Context::graphics();
    SimpleShaderProgram &program = g.simpleShader();
    const TextSystem &textSys = g.textSys();

    glClear(GL_COLOR_BUFFER_BIT);

    program.setAlpha(1.0f);
    triangle_.draw(program, &trianglePos_, nullptr, &fillColor_,
                   nullptr, 0, nullptr);
    square_.draw(program, &squarePos_, nullptr, &fillColor_,
                 &borderColor_, 0, nullptr);
    texRect_.draw(program, &texPos_, nullptr, nullptr,
                  nullptr, texture_.id(), nullptr);
    textSys.draw(program, "Hello world", Point2{600.0f, 300.0f},
                 TextSize::BIG, &fillColor_);
    textSys.draw(program, "Hello world", Point2{600.0f, 250.0f},
                 TextSize::MEDIUM, &fillColor_);
    textSys.draw(program, "Hello world", Point2{600.0f, 200.0f},
                 TextSize::SMALL, &fillColor_);
    textSys.draw(program, "Hello world", Point2{600.0f, 150.0f},
                 TextSize::TINY, &fillColor_);

    glFlush();

    postProcess();
}

void TestShapeApp::onViewportChange(float width1, float height1)
{
    App::onViewportChange(width1, height1);
    setupShader();
}

} // end of namespace tanktest
} // end of namespace mcdane

