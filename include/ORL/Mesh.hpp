/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_MESH_HPP__
#define __ORL_MESH_HPP__ 1
#include "Renderable.hpp"
#include "Vertex.hpp"
#include "Texture.hpp"
#include <vector>

namespace ORL
{
  /**
   *  Mesh - represents a mesh.
   */
  class Mesh : public RenderableWithShader, Noncopyable
  {
    std::vector<Texture> Textures;
    std::uint32_t NumIndices;
    std::uint32_t VA, VB[2];

  protected:
    void onRender(const Shader &S) override;

  public:
    explicit Mesh(std::vector<Vertex> &VV, std::vector<std::uint32_t> &VI, std::vector<Texture> &VT);
    virtual ~Mesh();
  };
}

#endif//__ORL_MESH_HPP__
