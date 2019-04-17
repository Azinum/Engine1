#version 330 core

// in vec3 colour;
in vec2 texCoord;
in vec3 surfaceNormal;
in vec3 toLight;

out vec4 outColour;

uniform sampler2D tex;

void main() {
  vec3 unitNormal = normalize(surfaceNormal);
  vec3 unitLight = normalize(toLight);

  float dotProduct = dot(unitNormal, unitLight);
  float brightness = max(dotProduct, 0.2f);
  vec3 diffuse = brightness * vec3(1, 1, 1);

  outColour = vec4(diffuse, 1.0f) * texture(tex, texCoord);
}
