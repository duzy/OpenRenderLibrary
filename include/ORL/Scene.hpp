/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_SCENE_HPP__
#define __ORL_SCENE_HPP__ 1
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Renderable.hpp"
#include "Noncopyable.hpp"
#include <memory>
#include <list>

namespace ORL
{
  using MeshPtr = std::shared_ptr<Mesh>;

  class Scene;

  /**
   *  MeshGroup - represents a group of meshes with the same shader.
   *
   *  A MeshGroup is used to load a model file.
   */
  class MeshGroup : public RenderableWithProjection, Noncopyable
  {
    friend Scene;
    
    using MeshList = std::list<MeshPtr>;

    MeshList Meshes;
    Shader Sha;
    std::int32_t MVPLoc;

  protected:
    void onRender(const mat4 &MVP) override;

  public:
    explicit MeshGroup(const std::string &VetexSource, const std::string &FragmentSource);
    virtual ~MeshGroup();

    void Load(const std::string &filename);
  };

  /**
   *  Scene - represents the model scene to contains objects.
   */
  class Scene : public Renderable
  {
    using MeshGroupList = std::list<std::shared_ptr<MeshGroup>>;

    mat4 ModelViewProjection;
    MeshGroupList MeshGroups;

  protected:
    void onRender() override;

  public:
    explicit Scene();
    virtual ~Scene();

    const mat4 &MVP() const { return ModelViewProjection; }
    mat4 &MVP() { return ModelViewProjection; }

    void Load(const std::string &ModelFilename, const std::string &VertexShaderFilename, const std::string &FragmentShaderFilename);

    void SetViewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height);
    void SetClearColor(float red, float green, float blue, float alpha);
  };
}

#endif//__ORL_SCENE_HPP__
