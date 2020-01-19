#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "ErrorCodes.h"
#include "ILogger.h"
#include "WasmBuilder.h"
using namespace std;

class ArgContent
{
public:
    string shortForm;
    string longForm;
    string description;
    int isMandatory;
    string value;
    int16_t (*func)(string );
};

class IParser
{

protected:
    ILogger *m_logger;
    vector<ArgContent> m_ListArgs;
    char **m_Argv;
    int m_Argc;
public:
    virtual ILogger *GetLogger() { return m_logger; }
    virtual vector<ArgContent> & GetArgList() { return m_ListArgs;}
    virtual int16_t ParseAndKeep() = 0;
    virtual void AddArgumentList(vector<ArgContent> ListArgs) {}
    virtual ~IParser() {}
};