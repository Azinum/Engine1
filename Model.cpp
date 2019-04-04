// Model.cpp

#include "Model.h"
#include "Window.h"

#include "Texture.h"

void storeInAttributeList(struct Model* model, int attribute, int count, unsigned int size, float* data);

struct Model createModel(const char* file) {
  struct Model model = {0};
  
  // Temporary till we use real model files
  float vertices[] = {
    -0.5f, 0.5f, 0,
    0.5f, 0.5f, 0,
    0.5f, -0.5f, 0,
    -0.5f, -0.5f, 0,
  };

  float textureCoords[] = {
    0, 0,
    1, 0,
    1, 1,
    0, 1, 
  };

  int indices[] = {
    // 0, 1, 2,
    // 2, 3, 0
    0, 3, 2,  // These are flipped
    2, 1, 0
  };

  Texture texture = loadTexture("Resources/Textures/Test.png");

  model.drawCount = ARRAY_SIZE(indices);

  glGenVertexArrays(1, &model.vao);
  glBindVertexArray(model.vao);

  storeInAttributeList(&model, 0, 3, sizeof(vertices), vertices);

  glGenBuffers(1, &model.ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, ARRAY_SIZE(indices) * sizeof(unsigned int), indices, GL_STATIC_DRAW);

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





