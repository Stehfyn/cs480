#include "engine.h"
#include <assert.h>

Engine::Engine(const char* name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
}


Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}


bool Engine::Initialize()
{
  //Hazel::Log::Init();
  srand(time(0));
  // Start a window 
  m_window = new Window(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT);
  //m_window = glfwCreateWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, m_WINDOW_NAME, NULL, NULL);

  if(!m_window->Initialize())
  {
    printf("The window failed to initialize.\n");
    return false;
  } 

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  m_Clock = new Clock();

  m_currentTimeMillis = GetCurrentTimeMillis();
  // No errors
  return true;
}


void Engine::Run()
{
  m_running = true;

  //while (!glfwWindowShouldClose(m_window->getWindow()))
  //{
  //    ProcessInput();
  //    //Display(m_window->getWindow(), m_Clock->Elapsed()); 1
  //    Display(nullptr, m_Clock->Elapsed());
  //    glfwPollEvents();
  //}
  ProcessInput();
  //Display(m_window->getWindow(), 0);
  //Display(m_window->getWindow(), m_Clock->Elapsed());
  //    Display(nullptr, m_Clock->Elapsed());
  //glfwPollEvents();
  m_running = false;

}

void Engine::ProcessInput()
{
    
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->getWindow(), true);

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_RELEASE)
        m_graphics->getTriangle()->setSpeed(glm::vec3(0., 0., 0.));

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_RELEASE)
        m_graphics->getCube()->setSpeed(glm::vec3(0., 0., 0.));

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
        m_graphics->getTriangle()->setSpeed(glm::vec3(0., .1, 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
        m_graphics->getTriangle()->setSpeed(glm::vec3(0., -.1, 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
        m_graphics->getTriangle()->setSpeed(glm::vec3(.1, 0., 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
        m_graphics->getTriangle()->setSpeed(glm::vec3(-.1, 0., 0.));

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
        m_graphics->getCube()->setSpeed(glm::vec3(0., .1, 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
        m_graphics->getCube()->setSpeed(glm::vec3(0., -.1, 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
        m_graphics->getCube()->setSpeed(glm::vec3(-.1, 0., 0.));
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
        m_graphics->getCube()->setSpeed(glm::vec3(.1, 0., 0.));

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_P) == GLFW_PRESS)
        m_graphics->getCube()->m_Clockwise = true;
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_O) == GLFW_PRESS)
        m_graphics->getCube()->m_Clockwise = false;


}

long long Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  //HZ_CORE_TRACE("{0}", DeltaTimeMillis);
  return DeltaTimeMillis;
  //return glfwGetTime();
}

long long Engine::GetCurrentTimeMillis()
{
  //timeval t;
  //gettimeofday(&t, NULL);
  //long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  //return ret;
    return (long long) glfwGetTime();
}

void Engine::Display(GLFWwindow* window, double time) {


    m_graphics->Render();

    m_window->Swap();
    //glfwSwapBuffers(m_window);

    m_graphics->Update(time, speed);
   // HZ_CORE_TRACE("{0}", time);
}
