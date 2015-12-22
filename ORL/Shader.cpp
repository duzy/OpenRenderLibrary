/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#include "ORL/Shader.hpp"
#include "internal/Console.hpp"
#include "internal/Driver.hpp"

static std::uint32_t NewShader(ORL::Console *Con, const ORL::Driver &GL, const char *Source, std::uint32_t type)
{
  auto Name = GL.CreateShader(type);
  if (!Name) {
    Con->Error("Shader: ", "CreateShader: ", GL.GetError());
    return Name;
  }

  GL.ShaderSource(Name, 1, &Source, NULL);
  GL.CompileShader(Name);

  std::int32_t compiled = 0;
  GL.GetShaderiv(Name, GL.COMPILE_STATUS, &compiled);
  if (!compiled) {
    std::int32_t infoLogLen = 0;
    GL.GetShaderiv(Name, GL.INFO_LOG_LENGTH, &infoLogLen);
    if (0 < infoLogLen) {
      std::string infoLog(infoLogLen, '\0');
      GL.GetShaderInfoLog(Name, infoLogLen, NULL, &infoLog[0]);
      Con->Error("CompileShader: ", infoLog);
    }
    GL.DeleteShader(Name);
    Name = 0;
  }

  return Name;
}

using namespace ORL;

Shader::Shader(const std::string &VertexSource, const std::string &FragmentSource)
  : ProgramName(0)
{
  const auto Con = Console::get();
  const auto &GL = Driver::get();

  ProgramName = GL.CreateProgram();
  if (!ProgramName) {
    Con->Error("Shader: ", "CreateProgram: ", GL.GetError());
    return;
  }

  auto VS = NewShader(Con, GL, VertexSource.c_str(), Driver::VERTEX_SHADER);
  auto FS = NewShader(Con, GL, FragmentSource.c_str(), Driver::FRAGMENT_SHADER);
  if (!VS || !FS) {
    Con->Error("Shader: ", "Bad Shaders!");
    Con->Debug("VertexShader & FragmentShader:",
               "\n----------\n", VertexSource,
               "\n----------\n", FragmentSource,
               "\n----------");
    return;
  }

  GL.AttachShader(ProgramName, VS);
  GL.AttachShader(ProgramName, FS);
  GL.LinkProgram(ProgramName);

  /* Delete the shaders as they're linked into the program now and no longer necessery.
   */
  GL.DeleteShader(VS);
  GL.DeleteShader(FS);

  std::int32_t LinkStatus = 0;
  GL.GetProgramiv(ProgramName, GL.LINK_STATUS, &LinkStatus);
  if (!LinkStatus) {
    std::int32_t InfoLogLen = 0;
    GL.GetProgramiv(ProgramName, GL.INFO_LOG_LENGTH, &InfoLogLen);
    if (0 < InfoLogLen) {
      std::string InfoLog(InfoLogLen, '\0');
      GL.GetProgramInfoLog(ProgramName, InfoLogLen, NULL, &InfoLog[0]);
      Con->Error("Shader: LinkProgram: ", InfoLog);
      Con->Debug("VertexShader & FragmentShader:",
                 "\n----------\n", VertexSource,
                 "\n----------\n", FragmentSource,
                 "\n----------");
    } else {
      Con->Error("Shader: Not Linked: ");
    }
    GL.DeleteProgram(ProgramName);
    ProgramName = 0;
  }

#if 0
  std::int32_t ValidateStatus = 0;
  GL.GetProgramiv(ProgramName, GL.VALIDATE_STATUS, &ValidateStatus);
  if (!ValidateStatus) {
    Con->Error("Shader: Validate: ", ValidateStatus);
  }
#endif

  /// Shader is ready!
}

Shader::~Shader()
{
  const auto &GL = Driver::get();
  if (ProgramName) {
    GL.DeleteProgram(ProgramName);
  }
}

void Shader::Use() const
{
  const auto &GL = Driver::get();
  if (ProgramName) {
    GL.UseProgram(ProgramName);
  }
}
