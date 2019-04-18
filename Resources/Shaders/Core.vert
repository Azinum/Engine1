#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec3 normal;

// out vec3 colour;
out vec2 texCoord;
out vec3 surfaceNormal;
out vec3 toLight;

float fov = 80;

float zNear = 0.1f;
float zFar = 1000.0f;

mat4 projection = mat4(
  1/tan(fov/2)/(4/3),   0,     0,    0.0f,
  0,         1/tan(fov/2),     0,    0.0f,
  0,                    0,     -((zFar + zNear)/(zFar - zNear)),   -((2 * zFar * zNear)/(zFar - zNear)),
  0,                    0,     -1,    5.0f
);

vec3 lightPosition = vec3(2, 0, 3);

void main() {
  gl_Position = projection * vec4(position, 1);
  texCoord = vec2(texcoord.x, texcoord.y);

  surfaceNormal = (projection * vec4(normal, 0.0f)).xyz;
  toLight = lightPosition - position;
}
