/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
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
#include "ORL/Window.hpp"
#include "ORL/Scene.hpp"
#include <iostream>

static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};

namespace
{
  class Demo : public ORL::Window
  {
    ORL::Scene Scene;

  protected:
    void onKey(int key, int scancode, int action, int mods) override;

  public:
    Demo(const std::string &MFilename, const std::string &VSFilename, const std::string &FSFilename);
    ~Demo();

    void run();
  };
}

Demo::Demo(const std::string &MFilename, const std::string &VSFilename, const std::string &FSFilename)
  : Window("ORL Demo"), Scene()
{
  if (!IsReady()) {
    return;
  }

  // gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

  SwapInterval(1);

  Scene.Load(MFilename, VSFilename, FSFilename);
}

Demo::~Demo()
{
}

void Demo::onKey(int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    SetShouldClose(true);
}

void Demo::run()
{
  glm::mat4 &MVP = Scene.MVP();
  MVP = glm::scale(MVP, glm::vec3(1.5f, 1.5f, 1.5f));

  while (!ShouldClose()) {
    float ratio;
    int width, height;

    GetFramebufferSize(&width, &height);
    ratio = width / (float) height;

    MVP = glm::rotate(MVP, 0.01f, glm::vec3(1.0f, -1.0f, 0.5f));

    Scene.SetViewport(0, 0, width, height);
    Scene.SetClearColor(0.5, 0.5, 0.5, 1.0);
    Scene.Render();

    SwapBuffers();
    PollEvents();
  }
}

int main(int argc, char**argv)
{
  ORL::Windowing Guard;
  if (!Guard.Ready) {
    return EXIT_FAILURE;
  }

  if (argc != 4) {
    std::cout
      << argv[0] << " Demo.obj Demo.vs Demo.fs"
      << std::endl;
    return EXIT_FAILURE;
  }

  Demo(argv[1], argv[2], argv[3]).run();
  return EXIT_SUCCESS;
}
