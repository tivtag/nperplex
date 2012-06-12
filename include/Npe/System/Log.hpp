#pragma once

#include "Diagnostics/LogLevel.hpp"
#include "Diagnostics/Log.hpp"

/*
   Macros: Logging
   
   NPE_INFO  - Starts logging a <LogLevel::Info> message.
   NPE_WARN  - Starts logging a <LogLevel::Warn> message.
   NPE_ERROR - Starts logging a <LogLevel::Error> message.
   NPE_FAIL  - Starts logging a <LogLevel::Fail> message.
   NPE_DEBUG - Starts logging a <LogLevel::Debug> message.
   
   Example:
   > NPE_WARN << "Cat detected!" << npe::endl;
*/

/*
   Macros: Logging Configuration
   
   NPE_CONFIG_LOG_INFO_DISABLED  - If defined replaces interaction with <NPE_INFO> with no-ops.
   NPE_CONFIG_LOG_WARN_DISABLED  - If defined replaces interaction with <NPE_WARN> with no-ops.
   NPE_CONFIG_LOG_ERROR_DISABLED - If defined replaces interaction with <NPE_ERROR> with no-ops.
   NPE_CONFIG_LOG_FAIL_DISABLED  - If defined replaces interaction with <NPE_FAIL> with no-ops.
   NPE_CONFIG_LOG_DEBUG_DISABLED - If defined replaces interaction with <NPE_DEBUG> with no-ops.

   Warning:   
      Functions <<-ed into disabled logs are still executed.

      E.g. in the following code the function expensive_function() will still be executed even if NPE_CONFIG_LOG_DEBUG_DISABLED is defined.
      The output won't be formatted nor send to any <ILogListener>.

      >
      > NPE_DEBUG << expensive_function() << npe::endl;
      >
*/

#ifdef NPE_CONFIG_LOG_INFO_DISABLED
   #define NPE_INFO  DETAIL_NPE_LOG_DISABLED
#else
   #define NPE_INFO  DETAIL_NPE_LOG(Info)
#endif

#ifdef NPE_CONFIG_LOG_WARN_DISABLED
   #define NPE_WARN  DETAIL_NPE_LOG_DISABLED
#else
   #define NPE_WARN  DETAIL_NPE_LOG(Warn)
#endif

#ifdef NPE_CONFIG_LOG_ERROR_DISABLED
   #define NPE_ERROR  DETAIL_NPE_LOG_DISABLED
#else
   #define NPE_ERROR  DETAIL_NPE_LOG(Error)
#endif

#ifdef NPE_CONFIG_LOG_FAIL_DISABLED
   #define NPE_FAIL  DETAIL_NPE_LOG_DISABLED
#else
   #define NPE_FAIL  DETAIL_NPE_LOG(Fail)
#endif

#ifdef NPE_CONFIG_LOG_DEBUG_DISABLED
   #define NPE_DEBUG DETAIL_NPE_LOG_DISABLED
#else
   #define NPE_DEBUG DETAIL_NPE_LOG(Debug)
#endif
