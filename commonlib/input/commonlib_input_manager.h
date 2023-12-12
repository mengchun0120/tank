#ifndef INCLUDED_COMMONLIB_INPUT_MANAGER_H
#define INCLUDED_COMMONLIB_INPUT_MANAGER_H

#include <memory>
#include <functional>
#include <commonlib_fixed_queue.h>
#include <commonlib_input_event.h>
#include <commonlib_vector.h>

namespace mcdane {
namespace commonlib {

class InputManager {
public:
    inline static InputManager & instance();

    static void initInstance(GLFWwindow *window,
                             const Vector2 &viewportSize,
                             unsigned int inputQueueCapacity);

    InputManager(GLFWwindow *window,
                 const Vector2 &viewportSize,
                 unsigned int inputQueueCapacity);

    inline bool eventsFull() const;

    bool addMouseButtonEvent(float x,
                             float y,
                             int button,
                             int action,
                             int mods);

    bool addMouseMoveEvent(float x,
                           float y);

    bool addKeyEvent(int key,
                     int scancode,
                     int action,
                     int mods);

    void clear();

    inline bool enabled() const;

    void enable();

    void disable();

    ~InputManager();

    template <typename P>
    void processInput(P &processor);

    inline void setViewportSize(const Vector2 &viewportSize);

private:
    static std::shared_ptr<InputManager> k_instance;

    GLFWwindow *window_;
    FixedQueue<InputEvent> events_;
    bool enabled_;
    Vector2 viewportSize_;
};

InputManager & InputManager::instance()
{
    return *k_instance;
}

bool InputManager::enabled() const
{
    return enabled_;
}

bool InputManager::eventsFull() const
{
    return events_.full();
}

template <typename P>
void InputManager::processInput(P &processor)
{
    while (!events_.empty())
    {
        InputEvent e;
        events_.dequeue(e);
        if (!processor(e))
        {
            break;
        }
    }
}

void InputManager::setViewportSize(const Vector2 &viewportSize)
{
    viewportSize_ = viewportSize;
}

} // end of namespace commonlib
} // end of namespace mcdane

#endif

