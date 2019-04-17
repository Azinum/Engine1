// MeshLoader.h

#ifndef _MESHLOADER_H
#define _MESHLOADER_H

#include <vector>

struct RawMesh {
  bool isValid;
  unsigned int drawCount;
  std::vector<float> vertices;
  std::vector<unsigned int> indices;
  std::vector<float> uvs;
  std::vector<float> normals;
};

struct RawMesh loadRawMesh(const char* fileName);

void freeRawMesh(struct RawMesh* mesh);

#endif // _MESHLOADER_H