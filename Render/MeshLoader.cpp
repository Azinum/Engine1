// MeshLoader.cpp

#include "Render/MeshLoader.h"
#include "File.h"

#include <algorithm>

bool parseFile(struct RawMesh* mesh, char* path);

struct RawMesh loadRawMesh(const char* fileName) {
  struct RawMesh mesh = {0};
  
  char path[512] = {0};
  sprintf(path, "%s.obj", fileName);
  
  if (parseFile(&mesh, path)) {
    mesh.drawCount = mesh.indices.size();
  } else {
    printf("%s\n", "Failed to parse .obj file");
  }

  return mesh;
}

bool parseFile(struct RawMesh* mesh, char* path) {
  FILE* file = fopen(path, "r");
  if (!file) {
    printf("Failed to open file '%s'\n", path);
    fclose(file);
    return false;
  }
  std::vector<float> tempuvs;

  char word[128] = {0};
  while (true) {
    int result = fscanf(file, "%s", word);
    if (result == EOF) {
      break;
    }

    if (strcmp(word, "v") == 0) {
      float x, y, z;
      fscanf(file, "%f %f %f\n", &x, &y, &z);
      mesh->vertices.push_back(x);
      mesh->vertices.push_back(y);
      mesh->vertices.push_back(z);
    }
    // f => vertex / texture coord / normal
    else if (strcmp(word, "f") == 0) {
      unsigned int x[3], y[3], z[3];
      int match = fscanf(file, "%i/%i/%i %i/%i/%i %i/%i/%i\n",
        &x[0], &y[0], &z[0],
        &x[1], &y[1], &z[1],
        &x[2], &y[2], &z[2]
      );

      if (match != 9) {
        printf("%s\n", "Can't parse this .obj file");
        fclose(file);
        return false;
      }

      mesh->indices.push_back(x[0] - 1);
      mesh->indices.push_back(x[1] - 1);
      mesh->indices.push_back(x[2] - 1);

      mesh->uvIndices.push_back(y[0] - 1);
      mesh->uvIndices.push_back(y[1] - 1);
      mesh->uvIndices.push_back(y[2] - 1);
    }
    else if (strcmp(word, "vt") == 0) {
      float u, v;
      fscanf(file, "%f %f\n", &u, &v);
      tempuvs.push_back(u);
      tempuvs.push_back(v);
    }
  }

  mesh->uvs.resize(mesh->indices.size());

  for (int i = 0; i < mesh->indices.size(); i++) {
    unsigned int index = mesh->indices[i];
    float u, v;
    u = tempuvs[mesh->uvIndices[i] * 2];
    v = tempuvs[mesh->uvIndices[i] * 2 + 1];
    mesh->uvs[index * 2] = u;
    mesh->uvs[index * 2 + 1] = 1 - v;
  }

  fclose(file);
  return true;
}

void freeRawMesh(struct RawMesh* mesh) {
  if (!mesh) return;
  if (!mesh->isValid) return;

}