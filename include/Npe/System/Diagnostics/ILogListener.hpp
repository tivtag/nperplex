#pragma once

#include <Npe/System/NoVtable.hpp>
#include "LogMessage.hpp"

namespace npe
{
   /*
      Interface: ILogListener

      The system log sends all <LogMessage>s to all registered ILogListeners.

      See also:
         <StdLogListener>, <add_log_listener>, <clear_log_listeners>
   */
   struct NPE_NO_VTABLE ILogListener
   {
      virtual ~ILogListener() { }
      virtual void write(const npe::LogMessage& message) = 0;

   protected:
      ILogListener() { }
   };
}
