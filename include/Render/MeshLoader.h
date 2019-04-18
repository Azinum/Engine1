// MeshLoader.h

#ifndef _MESHLOADER_H
#define _MESHLOADER_H

#include "Render/Mesh.h"

#include <vector>

bool loadOBJ(struct RawMesh* mesh, const char* fileName);

#endif // _MESHLOADER_H