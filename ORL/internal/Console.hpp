/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  
 */
#ifndef __ORL_INTERNAL_CONSOLE_HPP__
#define __ORL_INTERNAL_CONSOLE_HPP__ 1
#include "ORL/Shader.hpp"
#include "ORL/Noncopyable.hpp"
#include <sstream>
#include <string>

namespace ORL
{
  class Console : private Noncopyable
  {
  protected:
    explicit Console();
    virtual ~Console();

    enum class LogLevel {
      INFO, DEBUG, WARN, ERROR,
    };

    virtual void LogMessage(LogLevel level, const std::string &message) = 0;

    std::ostringstream & BuildLogMessage(std::ostringstream &out) { return out; }

    template<typename Arg0, typename... Arg>
    std::ostringstream & BuildLogMessage(std::ostringstream &out, Arg0 arg, Arg... rest) {
      out << arg;
      return this->BuildLogMessage(out, rest...);
    }

    template<typename... Arg>
    void Log(LogLevel Level, Arg... args)
    {
      std::ostringstream ss;
      this->BuildLogMessage(ss, args...);
      this->LogMessage(Level, ss.str());
    }

  public:
    static Console *get();

    template<typename... Arg> void Info(Arg... args) { this->Log(LogLevel::INFO, args...); }
    template<typename... Arg> void Debug(Arg... args) { this->Log(LogLevel::DEBUG, args...); }
    template<typename... Arg> void Warn(Arg... args) { this->Log(LogLevel::WARN, args...); }
    template<typename... Arg> void Error(Arg... args) { this->Log(LogLevel::ERROR, args...); }
  };
}

#endif//__ORL_INTERNAL_CONSOLE_HPP__
