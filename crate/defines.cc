module;
#include <stdint.h>

#include "crate/platform.h"

export module crate:defines;

export namespace crate {

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

#if defined(IS_64BIT)
using usize = u64;
using isize = i64;
#elif defined(IS_32BIT)
using usize = u32;
using isize = i32;
#else
#error "target cpu is not supported"
#endif

};  // namespace crate
