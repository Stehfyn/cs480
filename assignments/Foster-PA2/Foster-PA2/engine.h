#ifndef ENGINE_H
#define ENGINE_H

#include "Base.h"
#include <assert.h>
#include "window.h"
#include "graphics.h"
#include "Clock.h"
class Engine
{
  public:
    Engine(const char*  name, int width, int height);
    
    ~Engine();
    bool Initialize();
    void Run();
    void ProcessInput();
    long long getDT();
    long long GetCurrentTimeMillis();
    void Display(GLFWwindow*, double);
    void setSpeed(glm::vec3 spd) { speed = spd; };
    
  
  private:
    // Window related variables
public:
    Window *m_window;

private:
    const char* m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;

    glm::vec3 speed = glm::vec3(0.f,0.f,0.f);
    Clock* m_Clock;
    Graphics *m_graphics;
public:
    GLuint m_TOF;
    bool m_running;
    long long m_currentTimeMillis;
};

#endif // ENGINE_H
