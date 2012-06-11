#pragma once

#if _MSC_VER >= 1100
#  define NPE_NO_VTABLE __declspec(novtable)
#else
#  define NPE_NO_VTABLE
#endif
