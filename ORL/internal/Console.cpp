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
#include "Console.hpp"
#include <iostream>

namespace
{
  class DefaultConsole : public ORL::Console
  {
  protected:
    void LogMessage(LogLevel level, const std::string &message);

  public:
    explicit DefaultConsole();
    virtual ~DefaultConsole();
  };
}

DefaultConsole::DefaultConsole()
{
}

DefaultConsole::~DefaultConsole()
{
}

void DefaultConsole::LogMessage(LogLevel Level, const std::string &Message)
{
  std::clog << "ORL: " ;
  switch (Level) {
  case LogLevel::INFO:  std::clog << "I: " ; break;
  case LogLevel::DEBUG: std::clog << "D: " ; break;
  case LogLevel::WARN:  std::clog << "W: " ; break;
  case LogLevel::ERROR: std::clog << "E: " ; break;
  }
  std::clog << Message << std::endl;
}

using namespace ORL;

Console::Console()
{
}

Console::~Console()
{
}

Console *Console::get()
{
  static DefaultConsole C;
  return &C;
}
