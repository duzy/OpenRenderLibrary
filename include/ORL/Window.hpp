/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_WINDOW_HPP__
#define __ORL_WINDOW_HPP__ 1
#define GLFW_INCLUDE_ES3 1
#include <GLFW/glfw3.h>
#include <iostream>
#include "Noncopyable.hpp"

namespace ORL
{

  /**
   *  Simple wrapping of GLFWwindow. This will help minifying the client code.
   */
  class Window : Noncopyable
  {
    GLFWwindow *Base;

  protected:
    virtual void onKey(int key, int scancode, int action, int mods) {}

  public:
    explicit Window(const std::string & Title, unsigned W = 640, unsigned H = 480)
      : Base(glfwCreateWindow(W, H, Title.c_str(), nullptr, nullptr))
    {
      if (Base) {
        glfwSetWindowUserPointer(Base, (void*) this);
        glfwSetKeyCallback(Base, KeyCalback);
        this->MakeContextCurrent();
      }
    }

    virtual ~Window()
    {
      if (Base) {
        glfwDestroyWindow(Base);
      }
    }

    bool IsReady() const { return Base != NULL; }

    bool ShouldClose() const { return glfwWindowShouldClose(Base); }
    void SetShouldClose(bool V) const { glfwSetWindowShouldClose(Base, V ? GLFW_TRUE : GLFW_FALSE); }

    void MakeContextCurrent() { glfwMakeContextCurrent(Base); }
    void SwapInterval(int interval) { glfwSwapInterval(interval); }
    void SwapBuffers() { glfwSwapBuffers(Base); }

    void GetFramebufferSize(int* width, int* height) { glfwGetFramebufferSize(Base, width, height); }

    static void PollEvents(void) { glfwPollEvents(); }
    static void WaitEvents(void) { glfwWaitEvents(); }
    static void PostEmptyEvent(void) { glfwPostEmptyEvent(); }

  private:
    static void KeyCalback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
      auto Self = (Window*) glfwGetWindowUserPointer(window);
      Self->onKey(key, scancode, action, mods);
    }
  };

  struct Windowing : private Noncopyable
  {
    const bool Ready;
    Windowing() : Ready(glfwInit())
    {
      if (Ready) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwSetErrorCallback(&ErrorCallback);
      }
    }
    ~Windowing()
    {
      if (Ready) {
        glfwTerminate();
      }
    }

  private:
    static void ErrorCallback(int error, const char* description)
    {
      std::cerr << "ORL::Windowing: ERROR[" << error << "]: " << description << std::endl;
    }
  };
}

#endif//__ORL_WINDOW_HPP__
