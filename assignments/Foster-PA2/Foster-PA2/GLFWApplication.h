#include "Application.h"
class GLFWApplication : Application
{
	GLFWApplication();
	~GLFWApplication();
protected:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
};