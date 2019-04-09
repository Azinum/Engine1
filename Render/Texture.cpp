// Texture.cpp

#include "Render/Texture.h"
#include "Render/Window.h"
#include "Render/ImageLoader.h"

#include <stdlib.h>


struct Texture loadTexture(const char* fileName) {
  struct Texture texture = {0};
  char path[512] = {0};
  sprintf(path, "%s%s", fileName, ".png");
  if (loadPNG(path, &texture.image)) {
    glGenTextures(1, &texture.textureId);
    glBindTexture(GL_TEXTURE_2D, texture.textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  // GL_REPEAT, GL_CLAMP_TO_EDGE
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.image.width, texture.image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.image.pixelBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);
    texture.isValid = true;
  } else {
    printf("Failed to load PNG file\n");
    texture.isValid = false;
  }

  return texture;
}

void useTexture(struct Texture* texture) {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->textureId);
}

void freeTexture(struct Texture* texture) {
  if (!texture) return;
  if (!texture->isValid) return;
  freePNG(texture->image.pixelBuffer);
  glDeleteTextures(1, &texture->textureId);
  texture->isValid = false;
}
