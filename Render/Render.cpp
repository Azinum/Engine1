// Render.cpp

#include "Render/Render.h"
#include "Render/Window.h"
#include "Render/Model.h"

void renderModel(struct Model* model) {
  if (!model) return;
  
  glBindVertexArray(model->vao);
  glEnableVertexAttribArray(0);
  glDrawElements(GL_TRIANGLES, model->drawCount, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}