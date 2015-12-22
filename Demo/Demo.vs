#version 300 es
precision mediump float;
in vec3 Position;
in vec3 Normal;
in vec2 Texel;
in vec3 Tangent;
in vec3 Bitangent;

out vec2 Coord;
out vec3 Norm;

uniform mat4 MVP;

void main()
{
  vec3 pos = Position;

  pos.y -= 0.4;

  gl_Position = MVP * vec4(pos, 1.0);

  Coord = Texel;
  Norm = Normal;
}
