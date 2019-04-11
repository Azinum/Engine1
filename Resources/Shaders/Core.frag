#version 330 core

// in vec3 colour;
in vec2 texCoord;

out vec4 outColour;

uniform sampler2D tex;

vec4 rgbToGray(vec4 rgbcolour) {
  float c = (rgbcolour.x + rgbcolour.y + rgbcolour.z) / 3;
  return vec4(c, c, c, rgbcolour.w);
}

void main() {
  outColour = texture(tex, texCoord);
  outColour = rgbToGray(outColour);

}
