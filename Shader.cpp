#include "Shader.h"
 

using namespace std;
void loadShaders(GLuint& gluint)
{
	cout << "load shader" << endl;
	char logInfo[512];
	GLint success;

	string temp="";
	string str="";
	std::ifstream fs;

	fs.open("./Shrader/shrader.glsl");

	if (fs.is_open()) {

		while (std::getline(fs, temp)) {
			str += temp + "\n";
		}
	}
	else {
		cout << "Error file"<<"\n";
	}

 

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* ch = str.c_str();
	glShaderSource(vertexShader, 1, &ch, NULL);
	glCompileShader(vertexShader);


	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, logInfo);
		std::cout << "ERROR! :: " << "\n";
		std::cout << logInfo << "\n";
	}

	glDeleteShader(vertexShader);
	fs.close();
	cout << "remove\n";
}

void loadFragmentShader(GLuint& gluint)
{
	char logInfo[512];
	GLint success;

	string temp = "";
	string str = "";
	std::ifstream fs;
	// Vertext 
	// 
	fs.open("./Shrader/shrader.glsl");

	if (fs.is_open()) {

		while (std::getline(fs, temp)) {
			str += temp + "\n";
		}
	}
	else {
		cout << "Error file" << "\n";
	}
	fs.close();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* ch = str.c_str();
	glShaderSource(vertexShader, 1, &ch, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, logInfo);
		std::cout << "ERROR! :: " << "\n";
		std::cout << logInfo << "\n";
	}

	temp = "";
	str = "";
	// Fragment
	fs.open("./Shrader/fragment_shader.glsl");

	if (fs.is_open()) {

		while (std::getline(fs, temp)) {
			str += temp + "\n";
		}
	}
	else {
		cout << "Error file fragment" << "\n";
	}
	fs.close();
	 

	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* ch1 = str.c_str();
	glShaderSource(fShader, 1, &ch1, NULL);
	glCompileShader(fShader);


	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fShader, 512, NULL, logInfo);
		std::cout << "ERROR! :: " << "\n";
		std::cout << logInfo << "\n";
	}
	// Program 
	gluint = glCreateProgram();
	glAttachShader(gluint, fShader);
	glAttachShader(gluint, vertexShader);

	// End 
 
	glUseProgram(0);
	glDeleteShader(vertexShader);
	glDeleteShader(fShader);
}
