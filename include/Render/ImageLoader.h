// ImageLoader.h

#ifndef _IMAGELOADER_H
#define _IMAGELOADER_H

struct Image {
  int width;
  int height;
  int format;
  unsigned char* pixelBuffer;
};

bool loadPNG(const char* fileName, struct Image* image);

void freePNG(unsigned char* pixelBuffer);

#endif // _IMAGELOADER_H