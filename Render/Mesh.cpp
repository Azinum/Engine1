// Mesh.cpp

#include "Render/Mesh.h"

void freeRawMesh(struct RawMesh* mesh) {
  if (!mesh) return;
  if (!mesh->isValid) return;
}