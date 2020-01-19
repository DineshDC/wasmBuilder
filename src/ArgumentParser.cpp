#include "ArgumentParser.h"
using namespace std;


ArgumentParser::ArgumentParser(int argc, char **argv){
        m_Argc = argc;
        m_Argv = argv;
        m_logger= new LogWasmToConsole();
}

void ArgumentParser::AddArgumentList(vector<ArgContent> ListArgs) {
    m_ListArgs = ListArgs;
}

vector<ArgContent>::iterator ArgumentParser::GetIterVector(string ValToFind){

 return find_if(m_ListArgs.begin(),m_ListArgs.end(),[&](const auto& val){ return (val.shortForm == ValToFind || val.longForm == ValToFind ) ; });
}

void ArgumentParser::PrintHelp() {
           if(m_logger) m_logger->PrintMessage( {"wasmbuild [option]\nOptions:"});
    for(auto a : m_ListArgs) {
        ArgContent tmp = a;

         if(m_logger){
            m_logger->PrintMsg( messageType::MESSAGE,enErrorCodes::SUCCESS,{"\t",tmp.shortForm , " or " ,tmp.longForm , "  " ,tmp.description},"");
         }
      }
}

int16_t ArgumentParser::ParseAndKeep() {

    if(m_Argc <= 2) {
        if(m_logger)
            m_logger->PrintMsg(messageType::ERROR,enErrorCodes::EERR_FEW_ARGS);
       
        PrintHelp();
        return -1;
    }
   for (int i = 1; i < m_Argc; ++i)
   {
       std::string tmpStr(m_Argv[i]);
       auto iter = GetIterVector(tmpStr);
       if(iter!=m_ListArgs.end()) {
           ArgContent &temp = *iter;
           temp.value = m_Argv[++i];
       }
       else {
           if(m_logger)
                m_logger->PrintMsg(messageType::ERROR,enErrorCodes::ERR_INVALID_ARG);
           return -1;
       }
   }
   
    return 0;
}