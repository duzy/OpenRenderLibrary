/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/OpenRenderLibrary
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_NONCOPYABLE_HPP__
#define __ORL_NONCOPYABLE_HPP__ 1

namespace ORL
{
  /**
   *  Noncopyable - represents a noncopyable object.
   */
  class Noncopyable
  {
  protected:
    constexpr Noncopyable() = default;
    ~Noncopyable() = default;

    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(const Noncopyable&) = delete;
  };
}

#endif//__ORL_NONCOPYABLE_HPP__
