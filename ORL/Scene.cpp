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
#include "ORL/Scene.hpp"
#include "internal/Console.hpp"
#include "internal/Driver.hpp"
#include "internal/ext/SOIL.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <map>

namespace
{
  struct ModelLoader
  {
    std::list<ORL::MeshPtr> &Meshes;
    const aiScene *Scene;
    std::string Directory;

    std::map<std::string, ORL::Texture> LoadedTextures;

    explicit ModelLoader(std::list<ORL::MeshPtr> &Out, const aiScene *S, const std::string &D)
      : Meshes(Out), Scene(S), Directory(D) {}

    void ProcessNode(aiNode* Node)
    {
      const auto Con = ORL::Console::get();
      Con->Debug("ModelLoader::ProcessNode: ", Node->mName.C_Str());

      // Process each mesh of the current node
      for (unsigned i = 0; i < Node->mNumMeshes; i++) {
        // The node object only contains indices to index the actual objects in the scene. 
        // The scene contains all the data, node is just to keep stuff organized (like
        // relations between nodes).
        auto M = Scene->mMeshes[Node->mMeshes[i]];
        this->Meshes.push_back(this->MakeMesh(M));
      }

      // Recursively process each of the children nodes
      for (unsigned i = 0; i < Node->mNumChildren; i++) {
        this->ProcessNode(Node->mChildren[i]);
      }
    }

    ORL::MeshPtr MakeMesh(aiMesh *M)
    {
      const auto Con = ORL::Console::get();

      std::vector<ORL::Vertex> Vertices;
      std::vector<std::uint32_t> Indices;
      std::vector<ORL::Texture> Textures;

      // If M->HasVertices()...
      for (unsigned i = 0; i < M->mNumVertices; ++i) {
        Vertices.emplace_back();
        ORL::Vertex &V = Vertices.back();

        if (M->HasPositions()) {
          const auto &iV = M->mVertices[i];
          V.Position = { iV.x, iV.y, iV.z };
        }

        if (M->HasNormals()) {
          const auto &iN = M->mNormals[i];
          V.Normal = { iN.x, iN.y, iN.z };
        }

        if (M->HasTextureCoords(0)) {
          const auto &TC = M->mTextureCoords[0][i];
          V.Texel = { TC.x, TC.y };
        }

        if (M->HasTangentsAndBitangents()) {
          const auto &T = M->mTangents[i];
          const auto &B = M->mBitangents[i];
          V.Tangent = { T.x, T.y, T.z };
          V.Bitangent = { B.x, B.y, B.z };
        }
      }

      // If M->HasFaces()...
      for (unsigned i = 0; i < M->mNumFaces; ++i) {
        auto &Face = M->mFaces[i];
        for (unsigned j = 0; j < Face.mNumIndices; ++j) {
          Indices.push_back(Face.mIndices[j]);
        }
      }

      if (Scene->HasMaterials() && M->mMaterialIndex < Scene->mNumMaterials) {
        auto Material = Scene->mMaterials[M->mMaterialIndex];
        for (unsigned i = 0; i < Material->mNumProperties; ++i) {
          Con->Debug("ModelLoader::MakeMesh: Material.mProperties[", i, "]=", Material->mProperties[i]->mKey.C_Str());
        }
        LoadMaterialTextures(Textures, Material, aiTextureType_DIFFUSE,      ORL::TextureType::DIFFUSE);
        LoadMaterialTextures(Textures, Material, aiTextureType_SPECULAR,     ORL::TextureType::SPECULAR);
        LoadMaterialTextures(Textures, Material, aiTextureType_AMBIENT,      ORL::TextureType::AMBIENT);
        LoadMaterialTextures(Textures, Material, aiTextureType_EMISSIVE,     ORL::TextureType::EMISSIVE);
        LoadMaterialTextures(Textures, Material, aiTextureType_HEIGHT,       ORL::TextureType::HEIGHT);
        LoadMaterialTextures(Textures, Material, aiTextureType_NORMALS,      ORL::TextureType::NORMALS);
        LoadMaterialTextures(Textures, Material, aiTextureType_SHININESS,    ORL::TextureType::SHININESS);
        LoadMaterialTextures(Textures, Material, aiTextureType_OPACITY,      ORL::TextureType::OPACITY);
        LoadMaterialTextures(Textures, Material, aiTextureType_DISPLACEMENT, ORL::TextureType::DISPLACEMENT);
        LoadMaterialTextures(Textures, Material, aiTextureType_LIGHTMAP,     ORL::TextureType::LIGHTMAP);
        LoadMaterialTextures(Textures, Material, aiTextureType_REFLECTION,   ORL::TextureType::REFLECTION);
      }

      Con->Debug("ModelLoader::MakeMesh: ", Vertices.size(), ", ", Indices.size(), ", ", Textures.size(),
                 ", ", M->mMaterialIndex, "/", Scene->mNumMaterials);

      return ORL::MeshPtr(new ORL::Mesh(Vertices, Indices, Textures));
    }

    unsigned LoadMaterialTextures(std::vector<ORL::Texture> &Textures, aiMaterial* Material, aiTextureType InType, ORL::TextureType OutType)
    {
      unsigned NumLoaded = 0;
      for (unsigned i = 0; i < Material->GetTextureCount(InType); ++i) {
        std::string TextureFilename;
        {
          aiString S;
          Material->GetTexture(InType, i, &S);
          TextureFilename = S.C_Str();
        }
        
        if (LoadedTextures.find(TextureFilename) != LoadedTextures.end()) {
          /// skip loaded texture
          continue;
        }

        ORL::Texture Tex{ LoadTextureFromFile(TextureFilename, false), OutType };
        if (0 < Tex.Name) {
          LoadedTextures.insert(std::make_pair(TextureFilename, Tex));
          Textures.push_back(Tex);
          NumLoaded += 1;
        }
      }
      return NumLoaded;
    }

    std::uint32_t LoadTextureFromFile(const std::string &Path, bool gamma)
    {
      const auto Con = ORL::Console::get();
      const auto &GL = ORL::Driver::get();

      auto Filename = (Path[0] == '/' ? Path : Directory + '/' + Path);

      std::uint32_t TextureName;
      GL.GenTextures(1, &TextureName);
      GL.BindTexture(GL.TEXTURE_2D, TextureName);

      auto const Start = std::chrono::high_resolution_clock::now();

      int Width = 0, Height = 0;
      unsigned InternalFormat = gamma ? unsigned(GL.SRGB) : unsigned(GL.RGB);
      unsigned char* Image = SOIL_load_image(Filename.c_str(), &Width, &Height, 0, SOIL_LOAD_RGB);
      GL.TexImage2D(GL.TEXTURE_2D, 0, InternalFormat, Width, Height, 0, GL.RGB, GL.UNSIGNED_BYTE, Image);
      SOIL_free_image_data(Image);

      auto const Stop = std::chrono::high_resolution_clock::now();
      float Duration = std::chrono::duration_cast<std::chrono::duration<float>>(Stop - Start).count();

      Con->Debug("ModelLoader::LoadTextureFromFile: ", Filename, ", ", Width, "x", Height, ", ", Duration);

      GL.GenerateMipmap(GL.TEXTURE_2D);	

      // Parameters
      GL.TexParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.REPEAT);
      GL.TexParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.REPEAT);
      GL.TexParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR);
      GL.TexParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
      GL.BindTexture(GL.TEXTURE_2D, 0);
      return TextureName;
    }
  }; // struct ModelLoader
}

static std::string LoadFileText(const std::string &Filename)
{
  std::stringstream StringStream;
  std::ifstream FileStream;
  FileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  FileStream.open(Filename);
  StringStream << FileStream.rdbuf();
  FileStream.close();
  return StringStream.str();
}

static glm::mat4 Camera(float Translate, glm::vec2 const & Rotate)
{
  glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.f);
  glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
  View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
  View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
  return Projection * View * Model;
}

using namespace ORL;

MeshGroup::MeshGroup(const std::string &VetexSource, const std::string &FragmentSource)
  : Meshes(), Sha(VetexSource, FragmentSource)
  , MVPLoc(Driver::get().GetUniformLocation(Sha.GetProgram(), "MVP"))
{
}

MeshGroup::~MeshGroup()
{
}

void MeshGroup::Load(const std::string &ModelFile)
{
  const auto Con = Console::get();

  Assimp::Importer Importer;
  auto Flag = aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace;
  auto Scene = Importer.ReadFile(ModelFile, Flag);
  if (!Scene /*|| Scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE*/ || !Scene->mRootNode) {
    Con->Error("MeshGroup::Load: ", "ReadFile: ", ModelFile);
    Con->Debug("MeshGroup::Load: ", "ReadFile: ", Importer.GetErrorString());
    return;
  }

  if (Scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE) {
    Con->Warn("MeshGroup::Load: ", "Scene is INCOMPLETE!");
  }

  auto Dir = ModelFile.substr(0, ModelFile.find_last_of('/'));
  ModelLoader(Meshes, Scene, Dir).ProcessNode(Scene->mRootNode);
}

void MeshGroup::onRender(const mat4 &MVP)
{
  //const auto Con = Console::get();
  const auto &GL = Driver::get();

  GL.UseProgram(Sha.GetProgram());
  GL.UniformMatrix4fv(MVPLoc, 1, GL.FALSE, (const float*) &MVP[0]);

  for (auto &M : Meshes) {
    M->Render(Sha);
  }
}

Scene::Scene()
  : MeshGroups()
  , ModelViewProjection(Camera(3.5f, vec2(glm::radians(45.0f), glm::radians(45.0f))))
{
}

Scene::~Scene()
{
}

void Scene::Load(const std::string &ModelFilename, const std::string &VertexShaderFilename, const std::string &FragmentShaderFilename)
{
  const auto Con = Console::get();
  try {
    auto VertexShaderSource = LoadFileText(VertexShaderFilename);
    auto FragmentShaderSource = LoadFileText(FragmentShaderFilename);
    MeshGroups.emplace_back(new MeshGroup(VertexShaderSource, FragmentShaderSource));
    MeshGroups.back()->Load(ModelFilename);
  } catch (const std::ifstream::failure &e) {
    Con->Error("Scene::Load: failure: ", e.what());
  }
}

void Scene::SetViewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height)
{
  const auto &GL = Driver::get();
  GL.Viewport(x, y, width, height);
}

void Scene::SetClearColor(float red, float green, float blue, float alpha)
{
  const auto &GL = Driver::get();
  GL.ClearColor(red, green, blue, alpha);
}

void Scene::onRender()
{
  const auto &GL = Driver::get();

  GL.Clear(GL.COLOR_BUFFER_BIT);

  for (const auto &G : MeshGroups) {
    G->Render(ModelViewProjection);
  }
}
