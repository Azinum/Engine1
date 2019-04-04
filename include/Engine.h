// Engine.h

#ifndef _ENGINE_H
#define _ENGINE_H

struct Engine;

int engineCreate(int argc, char** argv);

int engineExecute();

void engineDestroy();

#endif // _ENGINE_H