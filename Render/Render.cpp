// Render.cpp

#include "Render/Render.h"
#include "Render/Window.h"
#include "Render/Model.h"
#include "Render/Texture.h"

void renderModel(struct Model* model) {
  if (!model) return;
  
  glBindVertexArray(model->vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glDrawElements(GL_TRIANGLES, model->drawCount, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}

void renderTexturedModel(struct Model* model, struct Texture* texture) {
  if (!model) return;
  
  glBindVertexArray(model->vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->textureId);
  glDrawElements(GL_TRIANGLES, model->drawCount, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}