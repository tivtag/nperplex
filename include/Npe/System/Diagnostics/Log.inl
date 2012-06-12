
#include <sstream>
#include <vector>

#include <boost/noncopyable.hpp>
#include <boost/current_function.hpp>

#include <Npe/System/Pointer.hpp>
#include <Npe/System/ToString.hpp>

namespace npe
{
   namespace detail
   {
      /*
         Detail Macro: DETAIL_NPE_LOG(level)

         Starts a new log entry with file, function and line information. 
         Use <<-syntax to write to the log. End a log line using << npe::endl.
      */
      #define DETAIL_NPE_LOG(level) ::npe::detail::Log::instance.begin(::npe::LogLevel::level, __FILE__, BOOST_CURRENT_FUNCTION, __LINE__); ::npe::detail::NormalLog()

      /*
         Detail Macro: DETAIL_NPE_LOG_DISABLED
         
         Used to replace DETAIL_NPE_LOG(level) calls with a no-op version that logs absolutely nothings.

         Warning:
            Functions with side-effects will still be called on no-op logs!
      */
      #define DETAIL_NPE_LOG_DISABLED ::npe::detail::NoOpLog()
      
      /*
         Detail Class: Log

         Internal Singleton that manages aggregating of log messages and sending them
         off to <ILogListener>s.
         
         A log line ends and is flushed when either npe::endl is send to the log or
         when starting a new log message using e.g. <LOG_ERROR>.
      */
      class Log : private boost::noncopyable
      {
      public:
         static Log instance;
         ~Log() { flush(); }
         
         void push_back(const std::shared_ptr<npe::ILogListener>& listener)
         {
            listeners.push_back(listener);
         }

         void clear()
         {
            listeners.clear();
         }
      
         inline void begin(const LogLevel::Enum level, const std::string& fileName, const std::string& funcName, const int line)
         {
            flush();

            this->level = level;
            this->fileName = fileName;
            this->funcName = funcName;
            this->line = line;
         }
      
         void put(const char ch)
         {
            buffer.put(ch);
         }

         void write(const std::string& str)
         {
            buffer << str;
         }

         void flush();
         
      private:
         Log();
         typedef std::vector<std::shared_ptr<npe::ILogListener> > ListenerList;

         LogLevel::Enum level;
         std::string fileName;
         std::string funcName;
         int line;

         std::ostringstream buffer;
         ListenerList listeners;
      };
   }
   
   template <typename T>
   inline const detail::NormalLog operator<<(const detail::NormalLog, const T& value) 
   {
      detail::Log::instance.write(npe::to_str(value));
	   return detail::NormalLog();
   }

   template <typename T>
   inline const detail::NoOpLog operator<<(const detail::NoOpLog, const T&) 
   {
	   return detail::NoOpLog();
   }

   template <>
   inline const detail::NormalLog operator<<(const detail::NormalLog, const struct endl_tag&) 
   {
	   detail::Log::instance.put('\n');
	   detail::Log::instance.flush();
	   return detail::NormalLog();
   }
       
   template <>
   inline const detail::NoOpLog operator<<(const detail::NoOpLog, const struct endl_tag&) 
   {
	   return detail::NoOpLog();
   }
}
