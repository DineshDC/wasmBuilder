#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class IProject {
    
   public:
    virtual int8_t CreateProject(string projectName) = 0;
    virtual int8_t BuildProject(string projectName) = 0;
    virtual int8_t RunProject(string projectName) =0;
    virtual int8_t BuildAndRunProject(string projectName) =0;
    virtual int8_t DeleteProject(string projectName) {};
    virtual int8_t HotRun(string projectName) {};

    virtual ~IProject() {};
    virtual vector<string>& GetMonitorList() { return m_FoldersToMonitor;}
     string m_ProjectName;
    protected:
     vector<string> m_FoldersToMonitor;
     string m_ProjectPath;

};