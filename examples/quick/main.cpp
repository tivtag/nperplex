#include <iostream>

// #define NPE_CONFIG_LOG_INFO_DISABLED

#include <Npe/Math/Util.hpp>
#include <Npe/Window/Window.hpp>
#include <Npe/System/Log.hpp>

#include <Npe/System/Diagnostics/StdLogListener.hpp>
using namespace npe;

int main()
{
    NPE_INFO 
       << "Compiler=" 
       << NPE_COMPILER
       << " Compiler Version="
       << NPE_COMPILER_VERSION
#if defined(NPE_COMPILER_CPP11)
       << " Supports CP11!"
#endif
       << npe::endl;

    //NPE_WARN << "Warn! " << npe::close_enough(1.0f, 1.000001f) << " " << npe::close_enough(1.0f, 1.01f) << npe::endl;
    std::cin.ignore();
    return 0;
}
