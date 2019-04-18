// Mesh.h

#ifndef _MESH_H
#define _MESH_H

#include <vector>

struct RawMesh {
  bool isValid;
  unsigned int drawCount;
  std::vector<float> vertices;
  std::vector<unsigned int> indices;
  std::vector<float> uvs;
  std::vector<float> normals;
};

void freeRawMesh(struct RawMesh* mesh);

#endif