#pragma once
#include <iostream>

#include "ILogger.h"
class LogWasmToConsole : public ILogger {
 
public:
  void PrintMessage(std::vector<string> listofmsg,string delimiter = "  ") override;
  void PrintMsg(messageType t,enErrorCodes code,vector<string> listofmsg = {},string delimiter = " ") override;
  ~LogWasmToConsole() {}
};