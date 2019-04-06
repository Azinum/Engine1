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
    
  } else {
    printf("Failed to load PNG file\n");
  }

  return texture;
}

void freeTexture(struct Texture* texture) {
  freePNG(texture->image.pixelBuffer);
}
