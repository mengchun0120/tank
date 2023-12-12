#include <commonlib_log.h>
#include <commonlib_input_manager.h>

namespace mcdane {
namespace commonlib {

std::shared_ptr<InputManager> InputManager::k_instance;

bool validateInputManager(const std::string &func)
{
    InputManager &mgr = InputManager::instance();

    if (!mgr.enabled())
    {
        LOG_WARN << func << ": InputManager is disabled" << LOG_END;
        return false;
    }

    if (mgr.eventsFull())
    {
        LOG_WARN << "Input-event queue is full" << LOG_END;
        return false;
    }

    return true;
}

void handleMouseButton(GLFWwindow *window,
                       int button,
                       int action,
                       int mods)
{
    if (!validateInputManager(__func__))
    {
        return;
    }

    double x, y;
    glfwGetCursorPos(window, &x, &y);

    InputManager::instance().addMouseButtonEvent(
        static_cast<float>(x), static_cast<float>(y), button, action, mods
    );
}

void handleMouseMove(GLFWwindow *window,
                     double x,
                     double y)
{
    if (!validateInputManager(__func__))
    {
        return;
    }

    InputManager::instance().addMouseMoveEvent(
        static_cast<float>(x), static_cast<float>(y)
    );
}

void handleKey(GLFWwindow *window,
               int key,
               int scancode,
               int action,
               int mods)
{
    if (!validateInputManager(__func__))
    {
        return;
    }

    InputManager::instance().addKeyEvent(key, scancode, action, mods);
}

void InputManager::initInstance(GLFWwindow *window,
                                const Vector2 &viewportSize,
                                unsigned int inputQueueCapacity)
{
    if (k_instance)
    {
        LOG_WARN << "InputManger already initialized" << LOG_END;
        return;
    }

    k_instance.reset(
        new InputManager(window, viewportSize, inputQueueCapacity)
    );
}

InputManager::InputManager(GLFWwindow *window,
                           const Vector2 &viewportSize,
                           unsigned int inputQueueCapacity)
    : window_(window)
    , enabled_(false)
    , viewportSize_(viewportSize)
{
    events_.init(inputQueueCapacity);
}

InputManager::~InputManager()
{
    disable();
}

void InputManager::enable()
{
    if (enabled_)
    {
        return;
    }

    clear();
    glfwSetCursorPosCallback(window_, handleMouseMove);
    glfwSetMouseButtonCallback(window_, handleMouseButton);
    glfwSetKeyCallback(window_, handleKey);
    enabled_ = true;
}

void InputManager::disable()
{
    if (!enabled_)
    {
        return;
    }

    glfwSetCursorPosCallback(window_, nullptr);
    glfwSetMouseButtonCallback(window_, nullptr);
    glfwSetKeyCallback(window_, nullptr);
    enabled_ = false;
}

void InputManager::clear()
{
    events_.clear();
}

bool InputManager::addMouseButtonEvent(float x,
                                       float y,
                                       int button,
                                       int action,
                                       int mods)
{
    InputEvent e;
    e.setMouseButtonEvent(x, viewportSize_[1]-y,
                          button, action, mods);
    return events_.enqueue(e);
}

bool InputManager::addMouseMoveEvent(float x,
                                     float y)
{
    InputEvent e;
    e.setMouseMoveEvent(x, viewportSize_[1]-y);
    return events_.enqueue(e);
}

bool InputManager::addKeyEvent(int key,
                               int scancode,
                               int action,
                               int mods)
{
    InputEvent e;
    e.setKeyEvent(key, action, scancode, mods);
    return events_.enqueue(e);
}

} // end of namespace commonlib
} // end of namespace mcdane
