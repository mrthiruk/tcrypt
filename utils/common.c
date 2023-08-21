#include "utils/common.h"

INT64 tcrypt_gcd(INT64 a, INT64 b) {
	INT64 temp;
	while (b) {
		temp = b;
		b = a % temp;
		a = temp;
	}
	return a;
}

INT64 tcrypt_bgcd(INT64 a, INT64 b) {
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
