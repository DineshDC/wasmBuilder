#pragma once

#include <vector>

#include "ErrorCodes.h"
#include "color.h"


using namespace std;

enum class messageType {
        MESSAGE = 0x100,
        ERROR,
        WARNING
    };
class ILogger {

 
    public:
     virtual void PrintMessage(vector<string> listofmsg,string delimiter = " ") = 0;   
     virtual void PrintMsg(messageType t,enErrorCodes code,vector<string> listofmsg = {},string delimiter = " ") {};
     virtual ~ILogger() {};
};