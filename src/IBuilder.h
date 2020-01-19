#pragma once
#include <iostream>

#include <string>
using namespace std;
class IBuilder {
    public:
    static int16_t CreateProject(string Name){};
    static int16_t AddClass(string Name){};
    static int16_t AddEmccClass(string Name){};
    static int16_t Build(string Name ){};
    static int16_t Run(string Name ){};
    static int16_t BuildAndRun(string Name ){};

    static int16_t DeleteProject(string Name){};
    static int16_t DeleteClass(string Name){};
    static int16_t DeleteEmccClass(string Name){};
    virtual ~IBuilder() = 0;
};

