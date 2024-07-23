#include "shaderClass.h"

using namespace std;

string get_file_contents(const char* filename) // Получаем контент из файла
{
	ifstream in(filename, ios::binary); // Читаем каждый символ в файле
	if (in)
	{
		string contents;
		in.seekg(0, ios::end); // Вычленяем каждый символ
		contents.resize(in.tellg()); // Наполняем contents символами из файла
		in.seekg(0, ios::beg); // Вычленяем начальный символ
		in.read(&contents[0], contents.size()); // Читаем содержимое
		in.close(); // Закрываем файл
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) // Конструктор для создания шейдера
{
	string vertexCode = get_file_contents(vertexFile);
	string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // Создаем шейдер вершин
	glShaderSource(vertexShader, 1, &vertexSource, nullptr); // (ID шейдера, количество объектов, данные для шейдера, длина данных)
	glCompileShader(vertexShader); // Компилируем шейдеры

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // Создаем фрагментный шейдер
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr); // (ID шейдера, количество объектов, данные для шейдера, длина данных)
	glCompileShader(fragmentShader); // Компилируем шейдера

	ID = glCreateProgram(); // Создаем программу для шейдеров
	glAttachShader(ID, vertexShader); // Прикрепляем к ней шейдеры
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID); // Линкуем программу

	glDeleteShader(vertexShader); // Удаляем шейдеры, ведь они уже в памяти программы
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}