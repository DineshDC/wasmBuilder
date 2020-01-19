#pragma once
#include <iostream>
#include "ArgumentParser.h"
#include "LogWasmToConsole.h"
#include "WasmProject.h"
#include "IBuilder.h"


using namespace std;
class IParser;


class WasmBuilder : public IBuilder
{
private:
    ILogger *m_logger;
    IParser *m_Parser;
    

public:
    WasmBuilder(int ac, char** av);
    ~WasmBuilder();

    static IProject *m_Project;
    int16_t Init();
    int16_t Start();
    public:
    static int16_t CreateProject(string Name);
    static int16_t AddClass(string Name);
    static int16_t AddEmccClass(string Name);
    static int16_t Build(string Name );
    static int16_t Run(string Name );
    static int16_t BuildAndRun(string Name );
    static int16_t HotRun(string Name);

    static int16_t DeleteProject(string Name);
    static int16_t DeleteClass(string Name);
    static int16_t DeleteEmccClass(string Name);
};


