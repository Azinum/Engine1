#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;

// out vec3 colour;
out vec2 texCoord;

mat4 projection = mat4(
  3.0f/4.0f, 0,     0,    0.0f,
  0,         1,     0,    0.0f,
  0,         0,     0.5f, 0.5f,
  0,         0,     0,    1.5f
);

void main() {
  gl_Position = projection * vec4(position, 1);
  // colour = vec3(1, 0, 0);
  texCoord = vec2(texcoord.x, 1.0f - texcoord.y);
}
