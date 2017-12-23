//
// Shader.cpp
// Created by David Harabagiu on 23.12.2017
//

#include "Shader.hpp"

Shader::Shader(std::string VertexShaderFileName, std::string FragmentShaderFileName)
{
	std::string vertexShaderString = ReadShaderFile(VertexShaderFileName);
	const GLchar* vertexShaderPString = vertexShaderString.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderPString, NULL);
	glCompileShader(vertexShader);
	ShaderCompileLog(vertexShader);

	std::string fragmentShaderString = ReadShaderFile(FragmentShaderFileName);
	const GLchar* fragmentShaderPString = fragmentShaderString.c_str();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderPString, NULL);
	glCompileShader(fragmentShader);
	ShaderCompileLog(fragmentShader);

	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, vertexShader);
	glAttachShader(this->shaderProgram, fragmentShader);
	glLinkProgram(this->shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	ShaderLinkLog();
}

GLuint Shader::GetShaderProgram()
{
	return this->shaderProgram;
}

void Shader::UseShaderProgram()
{
	glUseProgram(this->shaderProgram);
}

std::string Shader::ReadShaderFile(std::string FileName)
{
	std::ifstream shaderFile;
	std::stringstream shaderStringStream;

	shaderFile.open(FileName);
	shaderStringStream << shaderFile.rdbuf();
	shaderFile.close();

	return shaderStringStream.str();
}

void Shader::ShaderCompileLog(GLuint ShaderId)
{
	GLint success;
	GLchar infoLog[MAX_LOG];

	glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(ShaderId, MAX_LOG, NULL, infoLog);
		std::cout << "Shader compilation error:\n" << infoLog << "\n";
	}
}

void Shader::ShaderLinkLog()
{
	GLint success;
	GLchar infoLog[MAX_LOG];

	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->shaderProgram, MAX_LOG, NULL, infoLog);
		std::cout << "Shader linking error:\n" << infoLog << "\n";
	}
}