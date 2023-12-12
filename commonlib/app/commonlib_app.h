#ifndef INCLUDED_COMMONLIB_APP_H
#define INCLUDED_COMMONLIB_APP_H

#include <string>
#include <commonlib_vector.h>
#include <commonlib_opengl.h>

namespace mcdane {
namespace commonlib {

class App {
public:
    static void initInstance(App *app);

    static void clearInstance();

    inline static App * instance();

    App(const std::string &name1="");

    virtual ~App();

    void init(unsigned int width1,
              unsigned int height1,
              const std::string &title);

    inline GLFWwindow * window();

    void run();

    inline const std::string & name() const;

    virtual void process();

    inline int width() const;

    inline int height() const;

    inline float viewportWidth() const;

    inline float viewportHeight() const;

    inline const commonlib::Point2 & viewportSize() const;

    inline bool running() const;

    inline void setRunning(bool running);

    inline bool shouldRun() const;

protected:
    void initViewportSize();

    void getViewportSize(float &width, float &height);

    void setViewportSize(float width, float height);

    virtual void onViewportChange(float width, float height);

    void setupOpenGL();

    void postProcess();

protected:
    static App *k_instance;
    GLFWwindow *window_;
    std::string name_;
    commonlib::Point2 viewportSize_;
    bool running_;
};

App * App::instance()
{
    return k_instance;
}

const std::string &App::name() const
{
    return name_;
}

float App::viewportWidth() const
{
    return viewportSize_[0];
}

float App::viewportHeight() const
{
    return viewportSize_[1];
}

const commonlib::Point2 &App::viewportSize() const
{
    return viewportSize_;
}

bool App::running() const
{
    return running_;
}

void App::setRunning(bool running)
{
    running_ = running;
}

GLFWwindow *App::window()
{
    return window_;
}

bool App::shouldRun() const
{
    return 0 == glfwWindowShouldClose(window_) && running_;
}

} // end of namespace commonlib
} // end of namespace mcdane

#endif
