// Model.cpp

#include "Render/Model.h"
#include "Render/Window.h"
#include "Render/MeshLoader.h"
#include "Render/Texture.h"

void storeInAttributeList(struct Model* model, int attribute, int count, unsigned int size, float* data);

struct Model createModel(const char* file) {
  struct Model model = {0};

  struct RawMesh mesh = loadRawMesh(file);

  model.drawCount = mesh.drawCount;

  glGenVertexArrays(1, &model.vao);
  glBindVertexArray(model.vao);

  storeInAttributeList(&model, 0, 3, mesh.vertices.size() * sizeof(float), &mesh.vertices[0]);
  storeInAttributeList(&model, 1, 2, mesh.uvs.size() * sizeof(float), &mesh.uvs[0]);
  storeInAttributeList(&model, 2, 3, mesh.normals.size() * sizeof(float), &mesh.normals[0]);
  
  glGenBuffers(1, &model.ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);
  return model;
}

void storeInAttributeList(struct Model* model, int attribute, int count, unsigned int size, float* data) {
  unsigned int vbo;
  
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  glEnableVertexAttribArray(attribute);
  glVertexAttribPointer(attribute, count, GL_FLOAT, GL_FALSE, 0, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
