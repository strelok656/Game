#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size) // Конструктор для создания буфера
{
	glGenBuffers(1, &ID); // Буфер (кол-во объектов, ссылка на буфер)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW); // Генерируем данные буфера(тип буфера, размер, данные, как использовать эти данные)
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}