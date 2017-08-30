

#include <stdint.h>

#include "run_config.h"

#if defined( CONFIG_HAS_PCLMULQDQ)||defined( CONFIG_PSHUFB )

#include "gf2ext-sse.hpp"


#ifdef _DEBUG_
static uint8_t log_tab0[16] = {0xc0,0x0,0x1,0x4, 0x2,0x8,0x5,0xa, 0x3,0xe,0x9,0x7, 0x6,0xd,0xb,0xc};
const uint8_t * _gf16_l0 = log_tab0;
#endif

#ifdef _DEBUG_
static uint8_t exp_tab0[32] = {0x1,0x2,0x4,0x8, 0x3,0x6,0xc,0xb, 0x5,0xa,0x7,0xe, 0xf,0xd,0x9,0x1
                ,0x2,0x4,0x8,0x3 ,0x6,0xc,0xb,0x5 ,0xa,0x7,0xe,0xf ,0xd,0x9,0x1,0x2};
const uint8_t * _gf16_e0 = exp_tab0;
#endif


#if defined( CONFIG_HAS_PCLMULQDQ )

/// gf2^103

/// X^103 + X^9 + 1
/// 103-64 = 39 -->  X^142 + X^48 + X39
/// X^128 + X^34 + X^25

template <>
const uint32_t gf2ext_sse<103>::_mask_Wbit[4] __attribute__((aligned(16)))
	= {0xffffffff,0xffffffff,0xffffffff,0x7f};

template <>
const uint64_t gf2ext_sse<103>::_reducer_W[2] __attribute__((aligned(16)))
	= {0x402000000ULL,0x201ULL};



//const uint32_t _mask_93bit[4] __attribute__((aligned(16)))
//		= {0xffffffff,0xffffffff,0x1fffffff,0};

template <>
const uint32_t gf2ext_sse<94>::_mask_Wbit[4] __attribute__((aligned(16)))
		= {0xffffffff,0xffffffff,0x3fffffff,0};

template <>
const uint32_t gf2ext_sse<95>::_mask_Wbit[4] __attribute__((aligned(16)))
		= {0xffffffff,0xffffffff,0x7fffffff,0};

template <>
const uint32_t gf2ext_sse<96>::_mask_Wbit[4] __attribute__((aligned(16)))
		= {0xffffffff,0xffffffff,0xffffffff,0};

template <>
const uint32_t gf2ext_sse<127>::_mask_Wbit[4] __attribute__((aligned(16)))
		= {0xffffffff,0xffffffff,0xffffffff,0x7fffffff,};


//const uint32_t _mask_96bit[4] __attribute__((aligned(16)))
//		= {0xffffffff,0xffffffff,0xffffffff,0};



/// gf2^96
///  x^96 + x^10 + x^9 + x^6 + 1
///  0x641
///  x^128 + x^42 + x^41 + x^38 + x^32
///  0x64100000000

template <>
const uint64_t gf2ext_sse<96>::_reducer_W[2] __attribute__((aligned(16)))
		= {0x64100000000ULL,0x641ULL};


/// gf2^95


/// x^95 + x^11 + 1
/// x^128 + x^44 + x^33
template <>
const uint64_t gf2ext_sse<95>::_reducer_W[2] __attribute__((aligned(16)))
		= {0x100200000000ULL,0x801ULL};

/// x^95 + x^7 + x^5 + x^3 + 1
/// x^128 + x^40 + x^38 + x^36 + x^33
///template <>
///const uint64_t gf2ext_sse<95>::_reducer_W[2] __attribute__((aligned(16)))
///		= {0x15200000000ULL,0xa9ULL};


/// x^95 + x^7 + x^5 + x^3 + 1
//const uint64_t _zero_95[2] __attribute__((aligned(16)))
//		= {0xa9ULL,0x80000000ULL};



/// gf2^94

/// x^94 + x^21 + 1
/// x^128 + x^55 + x^34
template <>
const uint64_t gf2ext_sse<94>::_reducer_W[2] __attribute__((aligned(16)))
		= {0x0080000400000000ULL,0x200001ULL};


/// X^94 + x^6 + x^5 + x + 1
/// X^96 + x^8 + x^7 + x^3 + x^2
/// X^128 + x^40 + x^39 + x^35 + x^34
///template <>
///const uint64_t gf2ext_sse<94>::_reducer_W[2] __attribute__((aligned(16)))
///		= {0x18c00000000ULL,0x63ULL};

/// X^94 + x^6 + x^5 + x + 1
//const uint64_t _zero_94[2] __attribute__((aligned(16)))
//		= {0x63ULL,0x40000000ULL};

/// X^95 + x^7 + x^6 + x^2 + x^1
//const uint64_t _zero_94_2[2] __attribute__((aligned(16)))
//		= {0xc6ULL,0x80000000ULL};


/// gf2^127

/// x^127 + x + 1
/// x^128 + x^2 + x
template <>
const uint64_t gf2ext_sse<127>::_reducer_W[2] __attribute__((aligned(16)))
		= {0x3ULL,0x6ULL};


#endif /// defined( CONFIG_HAS_PCLMULQDQ )


#if defined( CONFIG_PSHUFB )

#include "gf2ext-iso.h"

template <>
const uint8_t * gf2ext_sse_tbl<96>::isomorphism = isomorphism_96;

template <>
const uint8_t * gf2ext_sse_tbl<96>::isomorphism_1 = ivs_isomorphism_96;

template <>
const uint8_t * gf2ext_sse_tbl<128>::isomorphism = isomorphism_128;

template <>
const uint8_t * gf2ext_sse_tbl<128>::isomorphism_1 = ivs_isomorphism_128;


#endif /// defined( CONFIG_PSHUFB )



#endif /// defined( CONFIG_HAS_PCLMULQDQ)||defined( CONFIG_PSHUFB)
