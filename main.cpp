// main.cpp

#include "Engine/Engine.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (engineCreate(argc, argv) != 0) {
    printf("%s\n", "Failed to initialize engine");
    return -1;
  }
  engineExecute();
  engineDestroy();
  return 0;
}
