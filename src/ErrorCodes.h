#pragma once
#include <string>
using namespace std;

enum class enErrorCodes {

    SUCCESS,
    /*Project creation*/
    ERR_FAILED_TO_CREATE,
    ERR_FAILED_DELETE,
    ERR_PROJECT_ALREADY_PRESENT,
    ERR_UNABLE_TO_OPEN_FILE,

    /*Argument parsing*/
    ERR_INVALID_ARG,
    EERR_FEW_ARGS

    
   };
   
class ErrorCodes {
    public :
    static string ErrorCodeToString(enErrorCodes code);
    
};
