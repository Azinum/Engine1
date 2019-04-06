// Model.h

#ifndef _MODEL_H
#define _MODEL_H

struct Model {
  unsigned int drawCount;
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo; // Indices
};

struct Model createModel(const char* file);

void bindAttribute(int program, int index, const char* name);

#endif // _MODEL_H