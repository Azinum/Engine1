// Engine.h

#ifndef _ENGINE_H
#define _ENGINE_H

struct Engine {
  bool initialized;
  bool isRunning;
};

int engineCreate(int argc, char** argv);

struct Engine* engine();

int engineExecute();

void engineDestroy();

#endif // _ENGINE_H