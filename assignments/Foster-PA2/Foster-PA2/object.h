#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    virtual void Update(long long dt);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    virtual void createVertices() = 0;

    glm::mat4 GetModel();

    void setSpeed(glm::vec3 spd) { m_speed = spd; }

  protected:
    glm::mat4 model;

    glm::mat4 rotation;
    glm::mat4 translation;
    glm::mat4 scale;

    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
  private:
    GLuint vao;

    GLuint VB;
    GLuint IB;
protected:
    glm::vec3 m_speed = glm::vec3(0., 0., 0.);
    float angle;
};

#endif /* OBJECT_H */
