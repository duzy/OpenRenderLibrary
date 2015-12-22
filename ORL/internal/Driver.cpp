/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#include "Driver.hpp"
#include <GLES3/gl3.h>

using namespace ORL;

Driver::Driver()
{
}

Driver::~Driver()
{
}

const Driver & Driver::get()
{
  static Driver driver;
  return driver;
}

std::int32_t Driver::GetError(void) const { return (std::int32_t) glGetError(); }

void Driver::Viewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height) const { glViewport((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height); }
void Driver::Clear(unsigned mask) const { glClear((GLbitfield) mask); }
void Driver::ClearColor(float red, float green, float blue, float alpha) const { glClearColor((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha); }
void Driver::ClearDepthf(float d) const { glClearDepthf((GLfloat) d); }
void Driver::ClearStencil(std::int32_t s) const { glClearStencil((GLint) s); }

std::uint32_t Driver::CreateShader(std::uint32_t type) const { return (std::uint32_t) glCreateShader((GLenum) type); }
void Driver::DeleteShader(std::uint32_t shader) const { glDeleteShader((GLuint) shader); }
void Driver::ShaderSource(std::uint32_t shader, std::int32_t count, const char * const * string, const std::int32_t *length) const { glShaderSource((GLuint) shader, (GLsizei) count, (const GLchar *const*) string, (const GLint *) length); }
void Driver::CompileShader(std::uint32_t shader) const { glCompileShader((GLuint) shader); }

void Driver::GetShaderiv(std::uint32_t shader, std::int32_t pname, std::int32_t *params) const { glGetShaderiv((GLuint) shader, (GLenum) pname, (GLint *) params); }
void Driver::GetShaderInfoLog(std::uint32_t shader, std::int32_t bufSize, std::int32_t *length, char *infoLog) const { glGetShaderInfoLog((GLuint) shader, (GLsizei) bufSize, (GLsizei *) length, (GLchar *) infoLog); }

std::uint32_t Driver::CreateProgram(void) const { return (std::uint32_t) glCreateProgram(); }
void Driver::DeleteProgram(std::uint32_t program) const { glDeleteProgram((GLuint) program); }
void Driver::UseProgram(GLuint program) const { glUseProgram((GLuint) program); }
void Driver::ValidateProgram(GLuint program) const { glValidateProgram((GLuint) program); }
void Driver::AttachShader(std::uint32_t program, std::uint32_t shader) const { glAttachShader((GLuint) program, (GLuint) shader); }
void Driver::LinkProgram(std::uint32_t program) const { glLinkProgram((GLuint) program); }
void Driver::GetProgramiv(std::uint32_t program, std::int32_t pname, std::int32_t *params) const { glGetProgramiv((GLuint) program, (GLenum) pname, (GLint *) params); }
void Driver::GetProgramInfoLog(std::uint32_t program, std::int32_t bufSize, std::int32_t *length, char *infoLog) const { glGetProgramInfoLog((GLuint) program, (GLsizei) bufSize, (GLsizei *) length, (GLchar *) infoLog); }

void Driver::GenVertexArrays(std::int32_t n, std::uint32_t *arrays) const { glGenVertexArrays((GLsizei) n, (GLuint *) arrays); }
void Driver::DeleteVertexArrays(std::int32_t n, const std::uint32_t *arrays) const { glDeleteVertexArrays ((GLsizei) n, (const GLuint *) arrays); }
void Driver::BindVertexArray(GLuint array) const { glBindVertexArray((GLuint) array); }
void Driver::EnableVertexAttribArray(std::uint32_t index) const { glEnableVertexAttribArray((GLuint) index); }
void Driver::VertexAttribPointer(std::uint32_t index, std::int32_t size, std::uint32_t type, bool normalized, std::int32_t stride, const void *pointer) const { glVertexAttribPointer((GLuint) index, (GLint) size, (GLenum) type, (GLboolean) normalized, (GLsizei) stride, (const void *) pointer); }

void Driver::GenBuffers(std::int32_t n, std::uint32_t *buffers) const { glGenBuffers((GLsizei) n, (GLuint *) buffers); }
void Driver::BindBuffer(std::uint32_t target, std::uint32_t buffer) const { glBindBuffer((GLenum) target, (GLuint) buffer); }
void Driver::BindBufferRange(std::uint32_t target, std::uint32_t index, std::uint32_t buffer, std::uint32_t offset, std::uint32_t size) const { glBindBufferRange((GLenum) target, (GLuint) index, (GLuint) buffer, (GLintptr) offset, (GLsizeiptr) size); }
void Driver::BindBufferBase(std::uint32_t target, std::uint32_t index, std::uint32_t buffer) const { glBindBufferBase((GLenum) target, (GLuint) index, (GLuint) buffer); }
void Driver::DeleteBuffers(std::int32_t n, const std::uint32_t *buffers) const { glDeleteBuffers ((GLsizei) n, (const GLuint *) buffers); }

void Driver::GenerateMipmap(std::uint32_t target) const                               { glGenerateMipmap((GLenum) target); }
void Driver::GenFramebuffers(std::int32_t n, std::uint32_t *framebuffers) const       { glGenFramebuffers((GLsizei) n, (GLuint *) framebuffers); }
void Driver::GenRenderbuffers(std::int32_t n, std::uint32_t *renderbuffers) const     { glGenRenderbuffers((GLsizei) n, (GLuint *) renderbuffers); }

void Driver::GenTextures(std::int32_t n, std::uint32_t *textures) const { glGenTextures((GLsizei) n, (GLuint *) textures); }

void Driver::BufferData(std::uint32_t target, std::uint32_t size, const void *data, std::uint32_t usage) const
{
  glBufferData((GLenum) target, (GLsizeiptr) size, (const void *) data, (GLenum) usage);
}

void Driver::ActiveTexture(unsigned texture) const
{
  glActiveTexture(GL_TEXTURE0+texture);
}

GLint Driver::GetUniformLocation(std::uint32_t program, const char *name) const
{
  return glGetUniformLocation((GLuint) program, (const char *)name);
}

void Driver::BindTexture(std::uint32_t target, std::uint32_t texture) const
{
  glBindTexture((GLenum) target, (GLuint) texture);
}

void Driver::TexImage2D(std::uint32_t target, std::int32_t level, std::int32_t internalformat, std::int32_t width, std::int32_t height, std::int32_t border, std::uint32_t format, std::uint32_t type, const void *pixels) const
{
  glTexImage2D((GLenum) target, (GLint) level, (GLint) internalformat, (GLsizei) width, (GLsizei) height, (GLint) border, (GLenum) format, (GLenum) type, (const void *) pixels);
}

void Driver::TexParameterf(std::uint32_t target, std::uint32_t pname, float param) const
{
  glTexParameterf((GLenum) target, (GLenum) pname, (GLfloat) param);
}

void Driver::TexParameterfv(std::uint32_t target, std::uint32_t pname, const float *params) const
{
  glTexParameterfv((GLenum) target, (GLenum) pname, (const GLfloat *) params);
}

void Driver::TexParameteri(std::uint32_t target, std::uint32_t pname, std::int32_t param) const
{
  glTexParameteri((GLenum) target, (GLenum) pname, (GLint) param);
}

void Driver::TexParameteriv(std::uint32_t target, std::uint32_t pname, const std::int32_t *params) const
{
  glTexParameteriv((GLenum) target, (GLenum) pname, (const GLint *) params);
}

void Driver::TexSubImage2D(std::uint32_t target, std::int32_t level, std::int32_t xoffset, std::int32_t yoffset, std::int32_t width, std::int32_t height, std::uint32_t format, std::uint32_t type, const void *pixels) const
{
  glTexSubImage2D((GLenum) target, (GLint) level, (GLint) xoffset, (GLint) yoffset, (GLsizei) width, (GLsizei) height, (GLenum) format, (GLenum) type, (const void *) pixels);
}

void Driver::Uniform1f(std::int32_t location, float v0) const                                                         { glUniform1f((GLint) location, (GLfloat) v0); }
void Driver::Uniform1fv(std::int32_t location, std::int32_t count, const float *value) const                          { glUniform1fv((GLint) location, (GLsizei) count, (const GLfloat *) value); }
void Driver::Uniform1i(std::int32_t location, std::int32_t v0) const                                                  { glUniform1i((GLint) location, (GLint) v0); }
void Driver::Uniform1iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const                   { glUniform1iv((GLint) location, (GLsizei) count, (const GLint *) value); }
void Driver::Uniform2f(std::int32_t location, float v0, float v1) const                                               { glUniform2f((GLint) location, (GLfloat) v0, (GLfloat) v1); }
void Driver::Uniform2fv(std::int32_t location, std::int32_t count, const float *value) const                          { glUniform2fv((GLint) location, (GLsizei) count, (const GLfloat *) value); }
void Driver::Uniform2i(std::int32_t location, std::int32_t v0, std::int32_t v1) const                                 { glUniform2i((GLint) location, (GLint) v0, (GLint) v1); }
void Driver::Uniform2iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const                   { glUniform2iv((GLint) location, (GLsizei) count, (const GLint *) value); }
void Driver::Uniform3f(std::int32_t location, float v0, float v1, float v2) const                                     { glUniform3f((GLint) location, (GLfloat) v0, (GLfloat) v1, (GLfloat) v2); }
void Driver::Uniform3fv(std::int32_t location, std::int32_t count, const float *value) const                          { glUniform3fv((GLint) location, (GLsizei) count, (const GLfloat *) value); }
void Driver::Uniform3i(std::int32_t location, std::int32_t v0, std::int32_t v1, std::int32_t v2) const                { glUniform3i((GLint) location, (GLint) v0, (GLint) v1, (GLint) v2); }
void Driver::Uniform3iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const                   { glUniform3iv((GLint) location, (GLsizei) count, (const GLint *) value); }
void Driver::Uniform4f(std::int32_t location, float v0, float v1, float v2, float v3) const                           { glUniform4f((GLint) location, (GLfloat) v0, (GLfloat) v1, (GLfloat) v2, (GLfloat) v3); }
void Driver::Uniform4fv(std::int32_t location, std::int32_t count, const float *value) const                          { glUniform4fv((GLint) location, (GLsizei) count, (const GLfloat *) value); }
void Driver::Uniform4i(std::int32_t location, std::int32_t v0, std::int32_t v1, std::int32_t v2, std::int32_t v3) const { glUniform4i((GLint) location, (GLint) v0, (GLint) v1, (GLint) v2, (GLint) v3); }
void Driver::Uniform4iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const                   { glUniform4iv((GLint) location, (GLsizei) count, (const GLint *) value); }
void Driver::UniformMatrix2fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const    { glUniformMatrix2fv((GLint) location, (GLsizei) count, (GLboolean) transpose, (const GLfloat *) value); }
void Driver::UniformMatrix3fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const    { glUniformMatrix3fv((GLint) location, (GLsizei) count, (GLboolean) transpose, (const GLfloat *) value); }
void Driver::UniformMatrix4fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const    { glUniformMatrix4fv((GLint) location, (GLsizei) count, (GLboolean) transpose, (const GLfloat *) value); }

void Driver::DrawArrays(std::uint32_t mode, std::int32_t first, std::int32_t count) const                                                                     { glDrawArrays((GLenum) mode, (GLint) first, (GLsizei) count); }
void Driver::DrawArraysInstanced(std::uint32_t mode, std::int32_t first, std::int32_t count, std::int32_t instancecount) const                                { glDrawArraysInstanced((GLenum) mode, (GLint) first, (GLsizei) count, (GLsizei) instancecount); }
void Driver::DrawBuffers(std::int32_t n, const std::uint32_t *bufs) const                                                                                     { glDrawBuffers((GLsizei) n, (const GLenum *) bufs); }
void Driver::DrawElements(std::uint32_t mode, std::int32_t count, std::uint32_t type, const void *indices) const                                              { glDrawElements((GLenum) mode, (GLsizei) count, (GLenum) type, (const void *) indices); }
void Driver::DrawElementsInstanced(std::uint32_t mode, std::int32_t count, std::uint32_t type, const void *indices, std::int32_t instancecount) const         { glDrawElementsInstanced((GLenum) mode, (GLsizei) count, (GLenum) type, (const void *) indices, (GLsizei) instancecount); }
void Driver::DrawRangeElements(std::uint32_t mode, std::uint32_t start, std::uint32_t end, std::int32_t count, std::uint32_t type, const void *indices) const { glDrawRangeElements((GLenum) mode, (GLuint) start, (GLuint) end, (GLsizei) count, (GLenum) type, (const void *) indices); }
