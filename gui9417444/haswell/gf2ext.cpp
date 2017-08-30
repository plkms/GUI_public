

#include "gf2ext.hpp"

/// x^103 + x^9 + 1

template <>
const uint64_t gf2ext_u64<103>::_irrPoly[2] __attribute__((aligned(32))) = {0x201ULL,0x8000000000ULL};


/// x^96 + x^10 + x^9 + x^6o + 1
template <>
const uint64_t gf2ext_u64<96>::_irrPoly[2] __attribute__((aligned(32))) = {0x641ULL,0x100000000ULL};


/// x^95 + x^11 + 1
template <>
const uint64_t gf2ext_u64<95>::_irrPoly[2] __attribute__((aligned(32))) = {0x801ULL,0x80000000ULL};

/// x^95 + x^7 + x^5 + x^3 + 1
///template <>
///const uint64_t gf2ext_u64<95>::_irrPoly[2] __attribute__((aligned(32))) = {0xa9ULL,0x80000000ULL};


/// x^94 + x^21 + 1
template <>
const uint64_t gf2ext_u64<94>::_irrPoly[2] __attribute__((aligned(32))) = {0x200001ULL,0x40000000ULL};

/// X^94 + x^6 + x^5 + x + 1
///template <>
///const uint64_t gf2ext_u64<94>::_irrPoly[2] __attribute__((aligned(32))) = {0x63ULL,0x40000000ULL};

/// x^127 + x + 1
template <>
const uint64_t gf2ext_u64<127>::_irrPoly[2] __attribute__((aligned(32))) = {0x3ULL,0x8000000000000000ULL};


/// x^128 + x^7 + x^2 + x + 1
template <>
const uint64_t gf2ext_u64<128>::_irrPoly[2] __attribute__((aligned(32))) = {0x87ULL,0};

