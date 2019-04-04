// ImageLoader.cpp

#include "ImageLoader.h"
#include "Window.h"

#include <stdlib.h>
#include <stdio.h>
#include <png.h>

bool loadPNG(const char* fileName, struct Image* image) {
  FILE* file = fopen(fileName, "rb");
  if (!file) {
    return false;
  }

  unsigned char signature[8];
  if (fread(signature, 1, sizeof(signature), file) < 8) {
    fclose(file);
    return false;
  }
  if (png_sig_cmp(signature, 0, 8)) {
    fclose(file);
    return false;
  }

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) {
    fclose(file);
    return false;
  }

  png_infop info = png_create_info_struct(png);
  if (!info) {
    fclose(file);
    return false;
  }

  if (setjmp(png_jmpbuf(png))) {
    png_destroy_read_struct(&png, &info, NULL);
    fclose(file);
    
    if (image->pixelBuffer != NULL) {
      free(image->pixelBuffer);
      image->pixelBuffer = NULL;
    }

    return false;
  }

  png_init_io(png, file);

  png_set_sig_bytes(png, sizeof(signature));

  png_read_info(png, info);

  image->width = png_get_image_width(png, info);
  image->height = png_get_image_height(png, info);

  if (png_get_bit_depth(png, info) < 8) {
    png_set_packing(png);
  }

  if (png_get_valid(png, info, PNG_INFO_tRNS)) {
    png_set_tRNS_to_alpha(png);
  }

  switch (png_get_color_type(png, info)) {
    case PNG_COLOR_TYPE_GRAY: {
      image->format = GL_RGB;
      png_set_gray_to_rgb(png);
    }
      break;

    case PNG_COLOR_TYPE_GRAY_ALPHA: {
      image->format = GL_RGBA;
      png_set_gray_to_rgb(png);
    }
      break;

    case PNG_COLOR_TYPE_PALETTE: {
      image->format = GL_RGB;
      png_set_expand(png);
    }
      break;

    case PNG_COLOR_TYPE_RGB: {
      image->format = GL_RGB;
    }
      break;

    case PNG_COLOR_TYPE_RGBA: {
      image->format = GL_RGBA;
    }
      break;

    default: {
      image->format = -1;
      png_destroy_read_struct(&png, &info, NULL);
      fclose(file);
      return false;
    }
      break;
  }

  unsigned int bpp = png_get_rowbytes(png, info) / image->width;

  png_set_interlace_handling(png);

  png_read_update_info(png, info);

  image->pixelBuffer = (unsigned char*)malloc(sizeof(unsigned char) * (image->width) * (image->height) * bpp);

  png_bytep rows[image->height];

  unsigned char* pixels = image->pixelBuffer;
  for (int i = 0; i < image->height; i++) {
    rows[i] = pixels;
    pixels += image->width * bpp;
  }

  png_read_image(png, rows);

  png_read_end(png, NULL);

  png_destroy_read_struct(&png, &info, NULL);

  fclose(file);
  return true;
}


void freePNG(unsigned char* pixelBuffer) {
  if (pixelBuffer) {
    free(pixelBuffer);
  }
}