// @auth: Stephen Foster Oct '22 CS-480
// @repo: github.com/Stehfyn/cs480
// @assignment: 1.0
// @vers: 1.0
// @file: Source.cpp

#pragma comment(lib, "opengl32")
#pragma comment(lib, "glew32")
#pragma comment(lib, "glfw3")
#pragma comment(lib, "soil2-debug")

#include <iostream>
#include <glew-2.1.0/glew.h>
#include <glfw-3.3.8/glfw3.h>
//#include <glew-2.1.0/glu.h> //Not wrangled by glew, see https://stackoverflow.com/a/3933593 && https://stackoverflow.com/a/73303899
#include <GL/GLU.h>           //Windows SDK, at "C:\Program Files\Microsoft SDKs\Windows\vX.XA\Include\gl", see https://stackoverflow.com/a/3933593

static bool okay_to_close = true;
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_close_callback(GLFWwindow* window);
void error_callback(int err, const char* msg);

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		printf("GLFW Initialization: Failed!\n");
	}
	printf("GLFW Initialization: OK!\n");

	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	GLFWwindow* window = glfwCreateWindow(640, 480, "MyWindow", NULL, NULL);
	if (!window)
	{
		printf("GLFW Window Initialization: Failed!\n");
	}
	printf("GLFW Window Initialization: OK!\n");

	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowCloseCallback(window, window_close_callback);
	glfwMakeContextCurrent(window);

	if (glewInit())
	{
		printf("GLEW Initialization: Failed!\n");
	}
	printf("GLEW Initialization: OK!\n");

	glfwSwapInterval(1);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	GLuint Program;
	GLuint vao[1];

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vShaderSrc = "#version 460 \n void main() { gl_Position = vec4(0.0,0.0,0.0,1.0);} "; // 10/10 gl_position -> gl_Position
	const char* fShaderSrc = "#version 460 \n out vec4 color void main() { color = vec4(0.0,0.3,1.0,1.0);} ";

	glShaderSource(vShader, 1, &vShaderSrc, NULL);
	glShaderSource(fShader, 1, &fShaderSrc, NULL);

	glCompileShader(vShader);
	glCompileShader(fShader);

	Program = glCreateProgram();
	glAttachShader(Program, vShader);
	glAttachShader(Program, fShader);

	glLinkProgram(Program);

	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glPointSize(10.0f);
		glDrawArrays(GL_POINTS, 0, 1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
void window_close_callback(GLFWwindow* window)
{
	if (!okay_to_close)
	{
		glfwSetWindowShouldClose(window, GLFW_FALSE);
	}
}
void error_callback(int err, const char* msg)
{
	printf("ERROR CODE %d: %s", err, msg);
}
