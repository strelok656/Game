#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID); // ћассив вершин(кол-во объектов, ссылка на массив)
}

void VAO::LinkVBO(VBO VBO, GLuint layout) //  онструктор дл€ создани€ буфера
{
	VBO.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // (индекс, размер(от 1 до 4), тип данных, нормализировать или нет, промежуток между элементами, промежуток между началом и первым атрибутом)
	glEnableVertexAttribArray(0);
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}