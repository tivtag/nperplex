#include <Npe/System/Diagnostics/Log.hpp>
#include <Npe/System/Diagnostics/StdLogListener.hpp>
#include <Npe/System/Thread.hpp>

using namespace npe::detail;
Log Log::instance;

Log::Log()
{
   push_back(std::make_shared<npe::StdLogListener>());
}


void Log::write(const std::string text, const npe::LogSource& source)
{
#ifdef NPE_USE_THREADS
   static std::mutex mutex;
   std::scoped_lock lock(mutex);
#endif

   if(text.size() > 0)
   {
      const npe::LogMessage message(text, source.level, source.fileName, source.funcName, source.line);

      for(ListenerList::iterator itr = listeners.begin(); itr != listeners.end(); ++itr)
      {
         (*itr)->write(message);
      }
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
