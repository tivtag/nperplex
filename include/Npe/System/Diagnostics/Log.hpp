#pragma once

#include <sstream>
#include <vector>

#include <boost/noncopyable.hpp>
#include <boost/current_function.hpp>

#include <Npe/System/Pointer.hpp>
#include <Npe/System/ToString.hpp>

#include "ILogListener.hpp"

namespace npe
{
   /*
      Func: add_log_listener

      Tells the given <ILogListener> to listen to log messages send to the global system log.
   */
   void add_log_listener(const std::shared_ptr<npe::ILogListener>& listener);

   /*
      Func: clear_log_listeners

      Removes all <ILogListener>s from the global log.
   */
   void clear_log_listeners();

   /*
      Class: endl
         
      Used to write a new line and then flushing the <Log>.

      Example:
      >  LOG_ERROR << "Meow" << npe::endl;
   */
   struct endl_tag { /* tag struct; no members */ };
   static const struct endl_tag endl;
      
   namespace detail
   {
      /*
         Detail Macro: DETAIL_NPE_LOG(level)

         Starts a new log entry with file, function and line information. 
         Use <<-syntax to write to the log. End a log line using << npe::endl.
      */
      #define DETAIL_NPE_LOG(level) std::unique_ptr<::npe::detail::NormalLogStream>(new ::npe::detail::NormalLogStream(::npe::LogLevel::level, __FILE__, BOOST_CURRENT_FUNCTION, __LINE__))

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
         
         void push_back(const std::shared_ptr<npe::ILogListener>& listener)
         {
            listeners.push_back(listener);
         }

         void clear()
         {
            listeners.clear();
         }
      
         void write(const std::string text, const npe::LogSource& source);
         
      private:
         Log();
         typedef std::vector<std::shared_ptr<npe::ILogListener> > ListenerList;

         LogLevel::Enum level;
         std::string fileName;
         std::string funcName;
         int line;

         ListenerList listeners;
      };

      /*
         Detail Class: LogStream

         Used to no-op formatting of input values. Warning: Functions with side-effects are still executed
         even when using the no-op facade.
      */
      template<bool HasLog>
      struct LogStream { };
            
      template<> 
      struct LogStream<true> : public npe::LogSource
      {     
         LogStream(const LogLevel::Enum _level, const std::string& _fileName, const std::string& _funcName, const int _line)
            : LogSource(_level, _fileName, _funcName, _line)
         {
         }
         
         ~LogStream()
         {
            write_final_message();
         }
         
         void write(const std::string& str)
         {
            buffer << str;
         }

         void endl()
         {
            buffer.put('\n');
            flush();
         }

         void flush()
         {
            write_final_message();
            clear_buffer();
         }

      private:

         void write_final_message()
         {
            detail::Log::instance.write(buffer.str(), *this);
         }

         void clear_buffer()
         {
            buffer.str(std::string());
            buffer.clear();
         }
         
         std::ostringstream buffer;
      };

      typedef LogStream<true> NormalLogStream;
            
      template<> struct LogStream<false> { };            
      typedef LogStream<false> NoOpLogStream;
   }

   /*
      Operator: << T

      Writes the given value to the <Log>. This does not flush.
      The conversation of the value to a string can be customized by specializing <to_str> on T.
   */
   template <typename T>
   inline const std::unique_ptr<detail::NormalLogStream>& operator<<(const std::unique_ptr<detail::NormalLogStream>& log, const T& value)
   {
      log->write(npe::to_str(value));
      return log;
   }

   template <typename T>
   inline const detail::NoOpLogStream operator<<(const detail::NoOpLogStream, const T&)
   {
      return detail::NoOpLogStream();
   }

   /*
      Operator: << npe::endl

      Writes a new line and then flushing the <Log>.
   */
   inline const std::unique_ptr<detail::NormalLogStream>& operator<<(const std::unique_ptr<detail::NormalLogStream>& log, const struct endl_tag&)
   {
      log->endl();
      return log;
   }
       
   inline const detail::NoOpLogStream operator<<(const detail::NoOpLogStream, const struct endl_tag&)
   {
      return detail::NoOpLogStream();
   }
}
