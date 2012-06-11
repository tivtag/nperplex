#include <Npe/System/Diagnostics/Log.hpp>
#include <Npe/System/Diagnostics/StdLogListener.hpp>

using namespace npe::detail;
Log Log::instance;

Log::Log()
{
   push_back(std::make_shared<npe::StdLogListener>());
}

void Log::flush()
{
   buffer.flush();
   const std::string text = buffer.str();

   if(text.size() > 0)
   {
      const npe::LogMessage message(text, level, fileName, funcName, line);

      for(ListenerList::iterator itr = listeners.begin(); itr != listeners.end(); ++itr)
      {
         (*itr)->write(message);
      }

      buffer.str(std::string());
      buffer.clear();
   }
}

void npe::add_log_listener(const std::shared_ptr<npe::ILogListener>& listener)
{
   Log::instance.push_back(listener);
}
   
void npe::clear_log_listeners()
{
   Log::instance.clear();
}
