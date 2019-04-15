#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec3 normal;

// out vec3 colour;
out vec2 texCoord;
out vec3 surfaceNormal;
out vec3 toLight;

mat4 projection = mat4(
  3.0f/4.0f, 0,     0,    0.0f,
  0,         1,     0,    0.0f,
  0,         0,     1,    0.5f,
  0,        -4,     0,    7.5f
);

vec3 lightPosition = vec3(0, 2, -20);

void main() {
  gl_Position = projection * vec4(position, 1);
  texCoord = vec2(texcoord.x, texcoord.y);

  surfaceNormal = (projection * vec4(normal, 0.0f)).xyz;
  toLight = lightPosition - position;
}
