// Window.h

#ifndef _WINDOW_H
#define _WINDOW_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

#if __APPLE__

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

#include <GL/gl.h>

#endif

#define ARRAY_SIZE(arr) ((sizeof(arr)) / (sizeof(arr[0])))

struct Window;

int windowCreate(const char* title, int width, int height);

int windowEvent();

void windowClear();

void windowRender();

void windowDestroy();

#endif // _WINDOW_H