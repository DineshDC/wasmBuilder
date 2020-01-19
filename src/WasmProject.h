#pragma once

#include "IProject.h"
#include <fstream>
#include <string>
#include "ErrorCodes.h"
#include "Notify.h"
#include <experimental/filesystem>  
namespace fs = std::experimental::filesystem;

class WasmProject : public IProject {
   public:
    int8_t CreateProject(string projectName) override;
    int8_t BuildProject(string projectName) override;
    int8_t RunProject(string projectName) override;
    int8_t BuildAndRunProject(string projectName) override;
    int8_t DeleteProject(string projectName) override;
    int8_t HotRun(string projectName) override;

    WasmProject();
    ~WasmProject();


    private :
     int8_t ReplaceStrLine(string &line,const string& stringToReplace,const string& replaceWith);
     int8_t ReplaceContent();
     void GotoBuildDir();

    Notify  *m_Notify;
};