#pragma once

#include <Npe/System/Pointer.hpp>
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
         Detail Class: LogFilterFacade

         Used to no-op formatting of input values. Warning: Functions with side-effects are still executed
         even when using the no-op facade.
      */
      template<bool HasLog>
      struct LogFilterFacade { };      
            
      template<> struct LogFilterFacade<true> { };    
      typedef LogFilterFacade<true> NormalLog;
            
      template<> struct LogFilterFacade<false> { };            
      typedef LogFilterFacade<false> NoOpLog;
   }

   /*
      Operator: << T

      Writes the given value to the <Log>. This does not flush.
      The conversation of the value to a string can be customized by specializing <to_str> on T.
   */
   template <typename T>
   inline const detail::NormalLog operator<<(const detail::NormalLog, const T& value);

   template <typename T>
   inline const detail::NoOpLog operator<<(const detail::NoOpLog, const T&);

    /*
      Operator: << npe::endl

      Writes a new line and then flushing the <Log>.
   */
   template <>
   inline const detail::NormalLog operator<<(const detail::NormalLog, const struct endl_tag&);
       
   template <>
   inline const detail::NoOpLog operator<<(const detail::NoOpLog, const struct endl_tag&);
}

#include "Log.inl"
