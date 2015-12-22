#version 300 es
precision mediump float;
in vec2 Coord;
in vec3 Norm;

out vec4 Color;

uniform sampler2D ORL_Diffuse;
uniform sampler2D ORL_Specular;
uniform sampler2D ORL_Normals;

void main()
{
  Color  = vec4(0.0);
  Color += texture2D(ORL_Diffuse, Coord);  //.rgba;
  Color += texture2D(ORL_Specular, Coord); //.rgba;
  Color += texture2D(ORL_Normals, Coord);  //.rgba;
  //Color += vec4(Norm * 0.25, 1.0);
  //Color *= vec4(Norm, 1.0);
}
