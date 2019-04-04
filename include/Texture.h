// Texture.h

#ifndef _TEXTURE_H
#define _TEXTURE_H

struct Texture {
  int textureId;
  int width;
  int height;
  unsigned char* pixelBuffer;
};

struct Texture loadTexture(const char* fileName);

void deleteTexture(struct Texture texture);

#endif // _TEXTURE_H