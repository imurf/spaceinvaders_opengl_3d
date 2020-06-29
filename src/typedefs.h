#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <stddef.h>

#ifndef _ALWAYS_INLINE_
#if defined(__GNUC__)
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#else
#define _ALWAYS_LINE_ inline
#endif
#endif

#ifndef _FORCE_INLINE_
#ifdef DISABLE_FORCED_INLINE
#define _FORCE_INLINE_ inline
#else
#define _FORCE_INLINE_ _ALWAYS_INLINE_
#endif
#endif

#endif // _TYPEDEFS_H_
