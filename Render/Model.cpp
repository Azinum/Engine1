// Model.cpp

#include "Render/Model.h"
#include "Render/Window.h"
#include "Render/MeshLoader.h"
#include "Render/Texture.h"

void storeInAttributeList(struct Model* model, int attribute, int count, unsigned int size, float* data);

struct Model createModel(const char* file) {
  struct Model model = {0};

  if (loadOBJ(&model.mesh, file)) {
    model.drawCount = model.mesh.drawCount;

    glGenVertexArrays(1, &model.vao);
    glBindVertexArray(model.vao);

    storeInAttributeList(&model, 0, 3, model.mesh.vertices.size() * sizeof(float), &model.mesh.vertices[0]);
    storeInAttributeList(&model, 1, 2, model.mesh.uvs.size() * sizeof(float), &model.mesh.uvs[0]);
    storeInAttributeList(&model, 2, 3, model.mesh.normals.size() * sizeof(float), &model.mesh.normals[0]);
    
    glGenBuffers(1, &model.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.mesh.indices.size() * sizeof(unsigned int), &model.mesh.indices[0], GL_STATIC_DRAW);

    model.isValid = true;
  } else {
    printf("%s\n", "Failed to create model");
    model.isValid = false;
  }

  return model;
}

void storeInAttributeList(struct Model* model, int attribute, int count, unsigned int size, float* data) {
  // unsigned int vbo; // Need to free this from memory
  
  glGenBuffers(1, &model->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, model->vbo);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  glEnableVertexAttribArray(attribute);
  glVertexAttribPointer(attribute, count, GL_FLOAT, GL_FALSE, 0, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void freeModel(struct Model* model) {
  if (!model) return;
  glDeleteVertexArrays(1, &model->vao);
  glDeleteVertexArrays(1, &model->ebo);
  freeRawMesh(&model->mesh);
}