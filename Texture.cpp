// Texture.cpp

#include "Texture.h"
#include "Window.h"
#include "ImageLoader.h"

#include <stdlib.h>


struct Texture loadTexture(const char* fileName) {
  struct Texture texture = {0};

  if (loadPNG(fileName, &texture.width, &texture.height, texture.pixelBuffer)) {

  }

  return texture;
}

void deleteTexture(struct Texture texture) {

}