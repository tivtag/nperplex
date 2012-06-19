
#include <iostream>

#include <Npe/Window/Window.hpp>

using namespace npe;

int main()
{
   npe::Window window;
   window.create(npe::VideoMode(glm::size2(800, 600)), false);

   std::cin.ignore();   
   return 0;
}
