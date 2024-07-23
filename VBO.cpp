#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) // Конструктор для создания буфера
{
	glGenBuffers(1, &ID); // Буфер (кол-во объектов, ссылка на буфер)
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // Генерируем данные буфера(тип буфера, размер, данные, как использовать эти данные)
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}