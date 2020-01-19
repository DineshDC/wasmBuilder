#include "WasmBuilder.h"
IProject *WasmBuilder::m_Project = nullptr;

WasmBuilder::WasmBuilder(int ac, char **av)
{
    m_Parser = new ArgumentParser(ac, av);
    m_logger = m_Parser->GetLogger();
    m_Project = new WasmProject();

    
}

WasmBuilder::~WasmBuilder()
{
}

int16_t WasmBuilder::Init()
{

    m_Parser->AddArgumentList({
        {string("-nw"), string("--new"), string("create new project"), true, string(""), &WasmBuilder::CreateProject},
        {string("-cc"), string("--class"), string("add new class "), true, string(""), &WasmBuilder::AddClass},
        {string("-ec"), string("--emclass"), string("add class with ecmascripten with only public interfaces"), true, string(""), &WasmBuilder::AddEmccClass},
        {string("-pb"), string("--build"), string("build the project"), true, string(""), &WasmBuilder::Build},
        {string("-pr"), string("--run"), string("run the project"), true, string(""), &WasmBuilder::Run},
        {string("-pbr"), string("--buildandrun"), string("build and run the project"), true, string(""), &WasmBuilder::BuildAndRun},
        {string("-hr"), string("--hotrun"), string("run with notify that will identify changes src, www, libs folder and build the project and run"), true, string(""), &WasmBuilder::HotRun},
    });
    if (m_Parser->ParseAndKeep() != 0)
    {
        return -1;
    }


   
}
int16_t WasmBuilder::Start()
{
    auto aVect = m_Parser->GetArgList();
    for (auto it : aVect)
    {
        if (it.value != "")
        {
            it.func(it.value);
        }
    }
}

int16_t WasmBuilder::CreateProject(string Name)
{
    return m_Project->CreateProject(Name);
}

int16_t WasmBuilder::AddClass(string Name)
{

}
int16_t WasmBuilder::AddEmccClass(string Name)
{

}
int16_t WasmBuilder::DeleteProject(string Name)
{

}
int16_t WasmBuilder::DeleteClass(string Name)
{

}
int16_t WasmBuilder::DeleteEmccClass(string Name)
{

}

int16_t WasmBuilder::Build(string Name){
    return m_Project->BuildProject(Name);
}

int16_t WasmBuilder::Run(string Name){
    return m_Project->RunProject(Name);
}

int16_t WasmBuilder::BuildAndRun(string Name){
    return m_Project->BuildAndRunProject(Name);
}

int16_t WasmBuilder::HotRun(string Name){
    return m_Project->HotRun(Name);
}

// m_FoldersToMonitor