// File originates from the supercop project
// Authors: Eli Biham and Orr Dunkelman
//
// File contains modifications by: The Gulden developers
// All modifications:
// Copyright (c) 2019 The Gulden developers
// Authored by: Malcolm MacLeod (mmacleod@gmx.com)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#ifndef SHAVITE3_256_OPT_H
#define SHAVITE3_256_OPT_H
#include <stdint.h>
enum Shavite3OptSelection
{
    SOPT_NONE=0,
    SOPT_SSE3,
    SOPT_SSE3_AES,
    SOPT_SSE4,
    SOPT_SSE4_AES,
    SOPT_AVX,
    SOPT_AVX_AES,
    SOPT_AVX2,
    SOPT_AVX2_AES,
    SOPT_AVX512F,
    SOPT_AVX512F_AES,
};
extern Shavite3OptSelection shavite3_256_opt_selected;

struct shavite3_256_opt_hashState 
{
   uint64_t bitcount;                // The number of bits compressed so far
   uint8_t chaining_value[64];       // An array containing the chaining value
   uint8_t buffer[128];              // A buffer storing bytes until they are compressed
   uint8_t partial_byte=0;           // A byte to store a fraction of a byte in case the input is not fully byte alligned
   int DigestSize;                   // The requested digest size
   int BlockSize;                    // The message block size
};

extern bool (*selected_shavite3_256_opt_Init)(shavite3_256_opt_hashState* state);
extern bool (*selected_shavite3_256_opt_Update)(shavite3_256_opt_hashState* state, const unsigned char* data, uint64_t dataLenBytes);
extern bool (*selected_shavite3_256_opt_Final)(shavite3_256_opt_hashState* state, unsigned char* hashval);
#endif


#ifndef SHAVITE3_256_OPT_IMPL
#include "opt/shavite3_256_opt_sse3.h"
#include "opt/shavite3_256_opt_sse3_aes.h"
#include "opt/shavite3_256_opt_sse4.h"
#include "opt/shavite3_256_opt_sse4_aes.h"
#include "opt/shavite3_256_opt_avx.h"
#include "opt/shavite3_256_opt_avx_aes.h"
#include "opt/shavite3_256_opt_avx2.h"
#include "opt/shavite3_256_opt_avx2_aes.h"
#include "opt/shavite3_256_opt_avx512f.h"
#include "opt/shavite3_256_opt_avx512f_aes.h"
#else
#include "compat.h"
#include <compat/arch.h>
#include <compat/sse.h>

// Initialization of the internal state of the hash function
bool shavite3_256_opt_Init(shavite3_256_opt_hashState* state);

// Compressing the input data, and updating the internal state
bool shavite3_256_opt_Update(shavite3_256_opt_hashState* state, const unsigned char* data, uint64_t dataLenBytes);

// Performing the padding scheme, and dealing with any remaining bits
bool shavite3_256_opt_Final(shavite3_256_opt_hashState* state, unsigned char* hashval);
#endif