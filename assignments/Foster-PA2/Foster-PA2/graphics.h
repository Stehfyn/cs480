#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "cube.h"
#include "triangle.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(long long dt, glm::vec3 speed);
    void Render();

    Object* getInteractWith();

    Triangle* getTriangle() { return m_triangle; }
    Cube* getCube() { return m_cube; }

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_vertPos;
    GLint m_vertCol;

    Triangle* m_triangle;
    Cube* m_cube;

};

#endif /* GRAPHICS_H */
