/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_SHADER_HPP__
#define __ORL_SHADER_HPP__ 1
#include "Noncopyable.hpp"
#include <string>
#include <cstdint>

namespace ORL
{
  /**
   *  Shader - represents a OpenGL(ES) shader.
   */
  class Shader : Noncopyable
  {
    /* The name of the shader program.
     */
    std::uint32_t ProgramName;

  public:
    /**
     *  Construct a shader from GLSL source.
     */
    explicit Shader(const std::string &VetexSource, const std::string &FragmentSource);

    virtual ~Shader();

    /**
     *  Returns the name of the shader.
     */
    std::uint32_t GetProgram() const { return ProgramName; }

    /**
     *  Use this shader.
     */
    void Use() const;
  };
}

#endif//__ORL_SHADER_HPP__
