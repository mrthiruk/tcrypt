#ifndef _TCRYPT_COMMON_H_
#define _TCRYPT_COMMON_H_

#include <utils/types.h>

UINT64 tcrypt_gcd(UINT64 a, UINT64 b);

UINT64 tcrypt_bgcd(UINT64 a, UINT64 b);

UINT64 tcrypt_mi(INT64 num, INT64 mod);

#endif
