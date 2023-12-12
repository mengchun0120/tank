#include <memory>
#include <algorithm>
#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <commonlib_app.h>

namespace mcdane {
namespace commonlib {

App * App::k_instance = nullptr;

void App::initInstance(App *app)
{
    if (k_instance)
    {
        THROW_EXCEPT(MyException, "Only one instance of App is allowed");
    }

    k_instance = app;
}

void App::clearInstance()
{
    k_instance = nullptr;
}

void initGLFW()
{
    if (!glfwInit())
    {
        THROW_EXCEPT(OpenGLException, "glfwInit failed");
    }
}

void setWindowHints()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *createWindow(unsigned int width,
                         unsigned int height,
                         const std::string &title)
{
    GLFWwindow *window = glfwCreateWindow(width, height, title.c_str(),
                                          nullptr, nullptr);
    if (!window)
    {
        THROW_EXCEPT(OpenGLException, "glfwCreateWindow failed");
    }

    return window;
}

void makeContextCurrent(GLFWwindow *window)
{
    glfwMakeContextCurrent(window);
}

void setupInputMode(GLFWwindow *window)
{
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_LOCK_KEY_MODS, GL_TRUE);
}

void initGLEW()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        THROW_EXCEPT(OpenGLException, "glewInit failed");
    }
}

App::App(const std::string &name1)
    : window_(nullptr)
    , name_(name1)
    , viewportSize_{0.0f, 0.0f}
    , running_(false)
{
    initInstance(this);
}

App::~App()
{
    if (!window_)
    {
        glfwTerminate();
    }

    clearInstance();
}


void App::init(unsigned int width1,
               unsigned int height1,
               const std::string &title)
{
    initGLFW();
    setWindowHints();
    window_ = createWindow(width1, height1, title);
    makeContextCurrent(window_);
    setupInputMode(window_);
    initGLEW();

    setupOpenGL();
    initViewportSize();
    running_ = true;
}

void App::run()
{
    while (shouldRun())
    {
        process();
    }
}

void App::getViewportSize(float &width1, float &height1)
{
    int w, h;
    glfwGetFramebufferSize(window_, &w, &h);
    width1 = static_cast<float>(w);
    height1 = static_cast<float>(h);
}

void App::setupOpenGL()
{
    glEnable(GL_BLEND);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void App::postProcess()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

void App::process()
{
    float width, height;

    getViewportSize(width, height);
    if (width != viewportWidth() || height != viewportHeight())
    {
        onViewportChange(width, height);
    }
}

void App::initViewportSize()
{
    float width, height;

    getViewportSize(width, height);
    setViewportSize(width, height);
}

void App::setViewportSize(float width, float height)
{
    viewportSize_[0] = width;
    viewportSize_[1] = height;
    glViewport(0, 0, width, height);
}

void App::onViewportChange(float width, float height)
{
    setViewportSize(width, height);
}

} // end of namespace commonlib
} // end of namespace mcdane
