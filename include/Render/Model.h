// Model.h

#ifndef _MODEL_H
#define _MODEL_H

#include "Render/Mesh.h"

struct Model {
  bool isValid;
  unsigned int drawCount;
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo; // Indices
  struct RawMesh mesh;
};

struct Model createModel(const char* file);

void bindAttribute(int program, int index, const char* name);

void freeModel(struct Model* model);

#endif // _MODEL_H