/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_TEXTURE_HPP__
#define __ORL_TEXTURE_HPP__ 1
#include "Noncopyable.hpp"

namespace ORL
{
  enum class TextureType
  {
    /* The texture is unavailable or invalid.
     */
    NONE,

    /* The texture is combined with the diffuse lighting effect.
     */
      DIFFUSE,

    /* The texture is combined with the specular lighting effect.
     */
      SPECULAR,

    /* The texture is combined with the ambient lighting effect.
     */
      AMBIENT,

    /* The texture is added with lighting effect, but not influenced
     * by incoming light.
     */
      EMISSIVE,

    /* The texture is a height map.
     */
      HEIGHT,

    /* The texture is a (tangent space) normal-map.
     */
      NORMALS,

    /* The texture defines the glossiness of the material.
     */
      SHININESS,

    /* The texture defines per-pixel opacity.
     */
      OPACITY,

    /* Displacement texture
     */
      DISPLACEMENT,

    /* Lightmap texture (aka Ambient Occlusion)
     */
      LIGHTMAP,

    /* Reflection texture
     */
      REFLECTION,
  };

  struct Texture
  {
    std::uint32_t Name;
    TextureType Type;
  };
}

#endif//__ORL_TEXTURE_HPP__
