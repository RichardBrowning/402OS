#include "OSCheck.h"

std::string getOsName()
{
    #ifdef _WIN64 || _WIN32
    return "Windows";
    #elif __APPLE__ || __MACH__
    return "macOS";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}         