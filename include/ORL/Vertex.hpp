/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_VERTEX_HPP__
#define __ORL_VERTEX_HPP__ 1
/*
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x3.hpp>
#include <glm/mat2x4.hpp>
#include <glm/mat4x2.hpp>
#include <glm/mat4x3.hpp>
#include <glm/mat4x4.hpp>
*/
#include <glm/glm.hpp>


namespace ORL
{
  using glm::vec2;
  using glm::vec3;
  using glm::vec4;
  using glm::mat2;
  using glm::mat3;
  using glm::mat4;

  struct Vertex
  {
    vec3 Position;
    vec3 Normal;
    vec2 Texel;
    vec3 Tangent;
    vec3 Bitangent;
  };
}

#endif//__ORL_VERTEX_HPP__
