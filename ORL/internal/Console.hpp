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
