#include "ErrorCodes.h"

string ErrorCodes::ErrorCodeToString(enErrorCodes type){
    switch (type)
    {
        case enErrorCodes::SUCCESS: return "no error"; break;
        case enErrorCodes::ERR_FAILED_TO_CREATE: return "Error to create project "; break;
        case enErrorCodes::ERR_FAILED_DELETE: return "Error to delete project "; break;
        case enErrorCodes::ERR_PROJECT_ALREADY_PRESENT: return "Error: project already present "; break;
        case enErrorCodes::ERR_UNABLE_TO_OPEN_FILE: return "Error: unable to open file "; break;
        case enErrorCodes::EERR_FEW_ARGS: return "Error: very few argument See help below\n "; break;
        
        
        case enErrorCodes::ERR_INVALID_ARG: return "Error: invalid argument "; break;
        
        default: return "no error"; break;
    }
}