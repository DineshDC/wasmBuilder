#pragma once
#include "IParser.h"

#include "LogWasmToConsole.h"


class ArgumentParser : public IParser
{
    
protected:
 

    void AddArgumentList(vector<ArgContent> ListArgs);
    void PrintHelp();

public:
    
    vector<ArgContent>::iterator GetIterVector(string ValToFind);
    ArgumentParser(int argc, char **argv) ;
    int16_t ParseAndKeep() override;
    ~ArgumentParser() {}
};
