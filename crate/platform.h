/*
 * Check target CPU
 */

#if defined(__x86_64__) || defined(_M_X64)
#define IS_64BIT
#define IS_X86
#endif

#if defined(__i386__) || defined(_M_IX86)
#define IS_32BIT
#define IS_X86
#endif

// sanity check
#if defined(IS_64BIT) && defined(IS_32BIT)
#error "target cannot be 64bit and 32bit at the same time"
#endif
