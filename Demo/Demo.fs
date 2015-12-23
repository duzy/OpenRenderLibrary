#version 300 es
precision mediump float;
in vec2 Coord;
in vec3 Norm;

out vec4 Color;

uniform sampler2D ORL_Diffuse0;
uniform sampler2D ORL_Specular0;
uniform sampler2D ORL_Normals0;

void main()
{
  Color  = vec4(0.0);
  Color += texture2D(ORL_Diffuse0, Coord);
  Color += texture2D(ORL_Specular0, Coord);
  Color += texture2D(ORL_Normals0, Coord);
  //Color += vec4(Norm * 0.25, 1.0);
  //Color *= vec4(Norm, 1.0);
}
