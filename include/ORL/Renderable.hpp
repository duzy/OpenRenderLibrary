/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_RENDERABLE_HPP__
#define __ORL_RENDERABLE_HPP__ 1
#define GLM_FORCE_RADIANS 1
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ORL
{
  using glm::mat4;

  /**
   *  Predeclaration.
   */
  class Shader;

  /**
   *  Renderable - represents a renderable object.
   */
  class Renderable
  {
  protected:
    virtual void onRender() = 0;

  public:
    void Render()
    {
      this->onRender();
    }
  };

  /**
   *  RenderableWithShader - represents a renderable object.
   */
  class RenderableWithShader
  {
  protected:
    virtual void onRender(const Shader &S) = 0;

  public:
    void Render(const Shader &S)
    {
      this->onRender(S);
    }
  };

  /**
   *  RenderableWithProjection - represents a renderable object with a projection.
   */
  class RenderableWithProjection
  {
  protected:
    virtual void onRender(const mat4 &Projection) = 0;

  public:
    void Render(const mat4 &Projection)
    {
      this->onRender(Projection);
    }
  };
}

#endif//__ORL_RENDERABLE_HPP__
