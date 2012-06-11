#pragma once

namespace npe
{
   namespace detail
   {
      class WindowImpl;
   }

   class Window
   {
   public:
      Window();

      void test();

   private:
      detail::WindowImpl* impl;
   };
}
