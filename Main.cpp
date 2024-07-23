#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "EBO.h"
#include "VAO.h"
#include "VBO.h"

int main()
{
	GLfloat vertices[] = // Матрица координат вершин
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    0.0f,   0.8f, 0.3f, 0.02f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		0.0f,   0.45f, 0.67f, 0.1f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	0.0f,   0.99f, 0.99f, 0.99f,
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	0.0f,   0.22f, 0.34f, 0.45f,
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	0.0f,   0.56f, 0.67f, 0.78f,
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,		0.0f,   0.89f, 0.90f, 0.23f,
	};

	GLuint indices[] = // ID вершин
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	glfwInit(); //Запускаем GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Версия OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5); // Версия OpenGL
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Профиль настроек

	GLFWwindow* window = glfwCreateWindow(1024, 1024, "A Game", nullptr, nullptr); // Создаем окно
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL(); // Запускаем GLAD
	glViewport(0, 0, 824, 824); // Расположение "камеры" в пространстве

	Shader shaderProgram("vertexShader.vert", "fragmentShader.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}