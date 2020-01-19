#include "LogWasmToConsole.h"

void LogWasmToConsole::PrintMessage(vector<string> listofmsg,string delimiter) {
    string fullmsg;
    for(auto a: listofmsg) {
        fullmsg += a;
        fullmsg +=delimiter;
    }
    std::cout<<BOLD<<KBLU<< fullmsg <<RST<<"\n";
}

void LogWasmToConsole::PrintMsg(messageType t,enErrorCodes code,vector<string> listofmsg,string delimiter){
    string errString = "";
    switch (t)
    {
        case messageType::ERROR: {
            errString = BOLD + string(KRED);
            errString += ErrorCodes::ErrorCodeToString(code); 
            cout<<errString<<RST<<endl;
        }
        break;
        case messageType::WARNING: {
            errString = BOLD + string(KYEL);
            errString += ErrorCodes::ErrorCodeToString(code); 
            cout<<errString<<RST<<endl;
        }
        break;
        
        default:
            PrintMessage(listofmsg,delimiter);
            break;
    }
    
}