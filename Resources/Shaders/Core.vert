#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec3 normals;

// out vec3 colour;
out vec2 texCoord;

mat4 projection = mat4(
  3.0f/4.0f, 0,     0,    0.0f,
  0,         1,     0,    0.0f,
  0,         0,     1,    0.5f,
  0,         -4,     0,    6.0f
);

void main() {
  gl_Position = projection * vec4(position, 1);
  // colour = vec3(1, 0, 0);
  texCoord = vec2(texcoord.x, texcoord.y);
}
