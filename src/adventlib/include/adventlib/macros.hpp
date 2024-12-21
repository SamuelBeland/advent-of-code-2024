#pragma once

#define SB_DECLARE_DEFAULT_MEMBERS(x)                                                              \
	x() = default;                                                                                 \
	~x() = default;                                                                                \
	x(x const&) = default;                                                                         \
	x(x&&) = default;                                                                              \
	x& operator=(x const&) = default;                                                              \
	x& operator=(x&&) = default

#ifdef __GNUC__ // GCC 4.8+, Clang, Intel and other compilers compatible with GCC (-std=c++0x or
				// above)
#define SB_FORCE_INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER) // MSVC
#define SB_FORCE_INLINE __forceinline
#else
#error
#endif
