// Entity.h

#ifndef _ENTITY_H
#define _ENTITY_H

struct Vector3f {
  float x, y, z;
};

struct Transform {
  struct Vector3f position;
  struct Vector3f rotation;
  struct Vector3f scale;
};

struct Entity {
  struct Transform transform;
  int modelId;
};

#endif // _ENTITY_H