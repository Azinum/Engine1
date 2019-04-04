// Texture.cpp

#include "Texture.h"
#include "Window.h"
#include "ImageLoader.h"

#include <stdlib.h>


struct Texture loadTexture(const char* fileName) {
  struct Texture texture = {0};
  if (loadPNG(fileName, &texture.image)) {

  } else {
    printf("Failed to load PNG file\n");
  }

  return texture;
}

void freeTexture(struct Texture* texture) {
  freePNG(texture->image.pixelBuffer);
}
