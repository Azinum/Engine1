// Shader.cpp

#include "Render/Shader.h"
#include "Render/Window.h"
#include "File.h"

struct Shader createShader(const char* fileName) {
  struct Shader shader = {0};

  char path[512] = {0};
  sprintf(path, "%s%s", fileName, ".vert");
  const char* vertexSource = readEntireFile(path);
  sprintf(path, "%s%s", fileName, ".frag");
  const char* fragSource = readEntireFile(path);

  if (compileShader(&shader, vertexSource, fragSource)) {
    shader.isValid = 1;
  }

  glDeleteShader(shader.vertexShader);
  glDeleteShader(shader.fragmentShader);
  if (vertexSource) free((void*)vertexSource);
  if (fragSource) free((void*)fragSource);

  return shader;
}


bool compileShader(struct Shader* shader, const char* vertexSource, const char* fragSource) {
  int success;
  char log[512];

  shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shader->vertexShader, 1, &vertexSource, NULL);
  glCompileShader(shader->vertexShader);

  {
    glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader->vertexShader, 512, NULL, log);
      fprintf(stderr, "%s", log);
      return false;
    }
  }

  shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shader->fragmentShader, 1, &fragSource, NULL);
  glCompileShader(shader->fragmentShader);

  {
    glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader->fragmentShader, 512, NULL, log);
      fprintf(stderr, "%s", log);
      return false;
    }
  }

  shader->program = glCreateProgram();
  glAttachShader(shader->program, shader->vertexShader);
  glAttachShader(shader->program, shader->fragmentShader);
  glLinkProgram(shader->program);

  {
    glValidateProgram(shader->program);
    glGetProgramiv(shader->program, GL_VALIDATE_STATUS, &success);
    if (success != 1) {
      glGetProgramInfoLog(shader->program, 512, NULL, log);
      fprintf(stderr, "%s", log);
      return false;
    }
  }
  return true;
}

void useShader(struct Shader* shader) {
  if (shader->isValid) {
    glUseProgram(shader->program);
  }
}

void bindAttribute(int program, int index, const char* name) {
  glBindAttribLocation(program, index, name);
}