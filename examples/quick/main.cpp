#include <iostream>

// #define NPE_CONFIG_LOG_INFO_DISABLED

#include <Npe/Math/Util.hpp>
#include <Npe/Window/Window.hpp>
#include <Npe/System/Log.hpp>

#include <Npe/System/Diagnostics/StdLogListener.hpp>
using namespace npe;

int main()
{
    //NPE_INFO 
    //   << "Hello! " 
    //   << 1234567890
    //   << npe::endl
    //   << "No!!"
    //   << npe::endl;

    npe::ILogListener* listener = new npe::StdLogListener();

    delete listener;



    //npe::Window window;
    //NPE_WARN << "Warn! " << npe::close_enough(1.0f, 1.000001f) << " " << npe::close_enough(1.0f, 1.01f) << npe::endl;
    //std::cin.ignore();
    return 0;
}
