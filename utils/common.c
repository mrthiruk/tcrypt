#include "utils/common.h"

#ifdef SWAP_F
static void swap_uint64(UINT64 a[static 1], UINT64 b[static 1]);
#endif

UINT64 tcrypt_gcd(UINT64 a, UINT64 b) {
	UINT64 temp;
	while (b) {
		temp = b;
		b = a % temp;
		a = temp;
	}
	return a;
}

UINT64 tcrypt_bgcd(UINT64 a, UINT64 b) {
	if (!b) {
		return a;
	}
	if (!a) {
		return b;
	}
	if (~a & 1) {
		if (b & 1) {
			return tcrypt_bgcd(a >> 1, b);
		} else {
			return (tcrypt_bgcd(a >> 1, b >> 1) << 1);
		}
	}
	if (~b & 1) {
		return tcrypt_bgcd(a, b >> 1);
	}
	if (a > b) {
		return tcrypt_bgcd((a - b) >> 1, b);
	}
	return tcrypt_bgcd((b - a) >> 1, a);
}

UINT64 tcrypt_mi(INT64 num, INT64 mod) {
	INT64 curr_x = 0,
		  prev_x = 1,
		  temp_x = 0;
	INT64 init_mod = mod,
		  temp_mod = 0;
	INT64 quotient = 0;
	while (mod) {
		quotient = num / mod;
		temp_x = prev_x - (quotient * curr_x);
		prev_x = curr_x;
		curr_x = temp_x;
		temp_mod = num % mod;
		num = mod;
		mod = temp_mod;
	}
	if (num == 1) {
		return (UINT64) ((prev_x + init_mod) % init_mod);
	}
	return 0;
}

#ifdef SWAP_F
static void swap_uint64(UINT64 a[static 1], UINT64 b[static 1]) {
	UINT64 *t = a;
	a = b;
	b = t;
}
#endif
