#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
using namespace std;

class Window
{
  public:
    Window(const char* name, int* width, int* height);
    ~Window();
    bool Initialize();
    void Swap();

    GLFWwindow* getWindow() {
        return gWindow;
    };

  public:
    GLFWwindow* gWindow;


};

#endif /* WINDOW_H */
