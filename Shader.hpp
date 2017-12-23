#pragma once

//
// Shader.hpp
// Created by David Harabagiu on 23.12.2017
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "OpenGLInclude.h"

#define MAX_LOG 512

class Shader
{

public:

	Shader(std::string VertexShaderFileName, std::string FragmentShaderFileName);
	void UseShaderProgram();
	GLuint GetShaderProgram();

private:
	
	GLuint shaderProgram;
	std::string ReadShaderFile(std::string FileName);
	void ShaderCompileLog(GLuint ShaderId);
	void ShaderLinkLog();

};