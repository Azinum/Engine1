#version 330 core

// in vec3 colour;
in vec2 texCoord;

out vec4 outColour;

uniform sampler2D tex;

void main() {
  outColour = texture(tex, texCoord);
}
