// Engine.cpp

#include "Engine/Engine.h"
#include "Render/Window.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Engine {
  bool initialized;
  bool isRunning;
};

static struct Engine _engine;

int engineCreate(int argc, char** argv) {
  srand(time(NULL));

  _engine = (struct Engine) {
    .initialized = true,
    .isRunning = true
  };

  if (windowCreate("Engine1 [768 x 512]", 768, 512) != 0) {
    printf("%s\n", "Failed to create window");
    return -1;
  }

  return 0;
}

int engineExecute() {
  if (_engine.initialized != 1) {
    printf("%s\n", "Can't execute engine (not initialized)");
    return -1;
  }

  while (_engine.isRunning && ((windowEvent() == 0))) {
    windowClear();
    windowRender();
  }

  return 0;
}

float engineGetTime();

void engineDestroy() {
  windowDestroy();
}