// Texture.h

#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "ImageLoader.h"

struct Texture {
  unsigned int textureId;
  struct Image image;
};

struct Texture loadTexture(const char* fileName);

void useTexture(struct Texture* texture);

void freeTexture(struct Texture* texture);

#endif // _TEXTURE_H