// Shader.h

#ifndef _SHADER_H
#define _SHADER_H

struct Shader {
  int isValid;
  int program;
  int vertexShader;
  int fragmentShader;
};

struct Shader createShader(const char* fileName);

bool compileShader(struct Shader* shader, const char* vertexSource, const char* fragSource);

void useShader(struct Shader shader);

void bindAttribute(int program, int index, const char* name);

#endif // _SHADER_H