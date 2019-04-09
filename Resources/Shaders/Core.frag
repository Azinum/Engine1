#version 330 core

in vec3 colour;
in vec2 texCoord;

out vec4 outColour;

uniform sampler2D tex;

void main() {
  // // outColour = vec4(colour, 1.0);
  outColour = texture(tex, texCoord);
}
