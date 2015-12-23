/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 */
#include "ORL/Mesh.hpp"
#include "internal/Console.hpp"
#include "internal/Driver.hpp"
#include <cstring>

/* This must be corresponding to ORL::TextureType, change correspondingly!
 */
static const char * const TextureSymbolNames[] = {
  "ORL_Diffuse",
  "ORL_Specular",
  "ORL_Ambient",
  "ORL_Emissive",
  "ORL_Height",
  "ORL_Normals",
  "ORL_Shininess",
  "ORL_Opacity",
  "ORL_Displacement",
  "ORL_Lightmap",
  "ORL_Reflection",
};

using namespace ORL;

Mesh::Mesh(std::vector<Vertex> &Vertices, std::vector<std::uint32_t> &Indices, std::vector<Texture> &VT)
  : Textures(VT), NumIndices(Indices.size()), VA(0), VB{0, 0}
{
  const auto Con = Console::get();
  const auto &GL = Driver::get();

  Con->Debug("Mesh: Vertices=", Vertices.size(), ", Indices=", Indices.size(), ", Textures=", Textures.size());
  for (unsigned i = 0; i < Textures.size(); ++i) {
    auto const &Tex = Textures[i];
    if (Tex.Type != TextureType::NONE) {
      auto Sym = TextureSymbolNames[unsigned(Tex.Type)];
      Con->Debug("Mesh: Textures[", i, "]=", Sym);
    }
  }

  GL.GenVertexArrays(1, &VA);
  GL.GenBuffers(2, VB);

  GL.BindVertexArray(VA);
  GL.BindBuffer(GL.ARRAY_BUFFER, VB[0]);
  GL.BufferData(GL.ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0], GL.STATIC_DRAW);
  GL.BindBuffer(GL.ELEMENT_ARRAY_BUFFER, VB[1]);
  GL.BufferData(GL.ELEMENT_ARRAY_BUFFER, NumIndices * sizeof(Indices[0]), &Indices[0], GL.STATIC_DRAW);

  GL.EnableVertexAttribArray(0);
  GL.VertexAttribPointer(0, 3, GL.FLOAT, 0/*GL_FALSE*/, sizeof(Vertex), (const void*) offsetof(Vertex, Position));
  GL.EnableVertexAttribArray(1);
  GL.VertexAttribPointer(1, 3, GL.FLOAT, 0/*GL_FALSE*/, sizeof(Vertex), (const void*) offsetof(Vertex, Normal));
  GL.EnableVertexAttribArray(2);
  GL.VertexAttribPointer(2, 2, GL.FLOAT, 0/*GL_FALSE*/, sizeof(Vertex), (const void*) offsetof(Vertex, Texel));
  GL.EnableVertexAttribArray(3);
  GL.VertexAttribPointer(3, 3, GL.FLOAT, 0/*GL_FALSE*/, sizeof(Vertex), (const void*) offsetof(Vertex, Tangent));
  GL.EnableVertexAttribArray(4);
  GL.VertexAttribPointer(4, 3, GL.FLOAT, 0/*GL_FALSE*/, sizeof(Vertex), (const void*) offsetof(Vertex, Bitangent));

  GL.BindVertexArray(0);
}

Mesh::~Mesh()
{
  const auto &GL = Driver::get();
  GL.DeleteBuffers(2, VB);
  GL.DeleteVertexArrays(1, &VA);
}

void Mesh::onRender(const Shader &S)
{
  //const auto Con = Console::get();
  const auto &GL = Driver::get();

  unsigned N[unsigned(TextureType::REFLECTION) + 1];
  std::memset(N, 0, sizeof(N));

  for (unsigned i = 0, n = 0; i < Textures.size(); ++i) {
    auto const &Tex = Textures[i];
    if (Tex.Type != TextureType::NONE) {
      auto T = unsigned(Tex.Type);
      auto Sym = std::string(TextureSymbolNames[T]) + char('0' + N[T]);
      auto Loc = GL.GetUniformLocation(S.GetProgram(), Sym.c_str());
      GL.ActiveTexture(GL.TEXTURE0 + n);
      GL.Uniform1i(Loc, n); // Set the sampler to the correct texture unit.
      GL.BindTexture(GL.TEXTURE_2D, Tex.Name);
      ++N[T];
      ++n;
    }
  }

  GL.BindVertexArray(VA);
  GL.DrawElements(GL.TRIANGLES, NumIndices, GL.UNSIGNED_INT, nullptr);
  GL.BindVertexArray(0);

  for (unsigned i = 0, n = 0; i < Textures.size(); ++i) {
    if (Textures[i].Type != TextureType::NONE) {
      GL.ActiveTexture(GL.TEXTURE0 + n);
      GL.BindTexture(GL.TEXTURE_2D, 0);
      ++n;
    }
  }
}
