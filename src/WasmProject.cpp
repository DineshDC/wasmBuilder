#include "WasmProject.h"

WasmProject::WasmProject()  {
    
}
WasmProject::~WasmProject()
{
}

int8_t WasmProject::ReplaceStrLine(string &lineToReplace, const string &stringToReplace, const string &replaceWith)
{
    size_t index = 0;

    while (true)
    {
        /* Locate the substring to replace. */
        index = lineToReplace.find(stringToReplace, index);
        if (index == std::string::npos)
            break;

        /* Make the replacement. */
        lineToReplace.replace(index, stringToReplace.length(), replaceWith);

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += stringToReplace.length();
    }
    return 0;
}

int8_t WasmProject::ReplaceContent()
{

    for (auto &p : fs::recursive_directory_iterator(m_ProjectPath))
    {
        auto tempVar = p.path();
        if (fs::is_directory(tempVar))
        {
            //cout<<tempVar<<endl;
        }
        else
        {

            string line;
            string tmpIn = tempVar.string();
            ifstream fileIn(tmpIn);
            string tmpOut = tmpIn + ".tmp";
            ofstream fileOut(tmpOut); //Temporary file

            if (!fileIn || !fileOut)
            {
                cout << ErrorCodes::ErrorCodeToString(enErrorCodes::ERR_UNABLE_TO_OPEN_FILE) << tmpOut << endl;
                return -1;
            }
            else
            {
                while (getline(fileIn, line))
                {
                    string strToreplace = "__PROJECT__";
                    ReplaceStrLine(line, strToreplace, m_ProjectName);
                    fileOut << line << "\n";
                }
                fileIn.close();
                fileOut.close();
                fs::remove(tmpIn);
                fs::rename(tmpOut, tmpIn);
            }
        }
    }
    return 0;
}
int8_t WasmProject::DeleteProject(string projectName)
{
}
int8_t WasmProject::CreateProject(string projectName)
{
    m_ProjectName = projectName;
    m_ProjectPath = fs::current_path().string() + "/" + projectName;

    if (fs::is_directory(m_ProjectPath))
    {
        std::cout << m_ProjectPath << ErrorCodes::ErrorCodeToString(enErrorCodes::ERR_PROJECT_ALREADY_PRESENT);
        return -1;
    }
    else
    {
        fs::create_directories(projectName);

        string srcPath = fs::current_path().string() + "/Template/";
        std::cout << srcPath << "---------" << m_ProjectPath << endl;

        fs::copy(srcPath, m_ProjectPath, fs::copy_options::recursive);
    }

    return ReplaceContent();
}

void WasmProject::GotoBuildDir()
{
    string buildDir = "build";
    if (!fs::is_directory(buildDir))
    {
        cout<<"Creatng Build directory\n";
        fs::create_directory(buildDir);
        //fs::remove_all(buildDir);
        //fs::create_directory(buildDir);
    }else {

         cout<<"=================="<<fs::current_path() <<"\n";
    }
        fs::current_path(buildDir);
        system("cmake ..");
}
int8_t WasmProject::BuildProject(string projectName)
{
    cout<<"Building project "<<projectName<<"\n";
    fs::current_path(projectName);
    GotoBuildDir();
    system("cmake ..");
    system("make");
}
int8_t WasmProject::RunProject(string projectName)
{
    fs::current_path(projectName);
    GotoBuildDir();
    fs::current_path("../www");
    cout<<"=================="<<fs::current_path()<<"\n";
    system("python -m SimpleHTTPServer BuildProject8000");
}

int8_t WasmProject::BuildAndRunProject(string projectName)
{
    fs::current_path(projectName);
    GotoBuildDir();
    system("make");
    system("cd ../www;python -m SimpleHTTPServer 8000 &");
}


int8_t WasmProject::HotRun(string projectName)
{
    m_ProjectName = projectName;
    cout<<"=================="<<fs::current_path();
    vector<string> paths = {  projectName + "/src",projectName + "/libs" };//projectName + "/www",
    m_FoldersToMonitor=std::move(paths);
    m_Notify = new Notify(this);
    m_Notify->Init();
    m_Notify->AddToWatch(m_FoldersToMonitor);
    BuildAndRunProject(projectName);
    m_Notify->Start();
    //m_Notify->Join();
}
