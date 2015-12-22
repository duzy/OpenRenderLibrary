/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
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
