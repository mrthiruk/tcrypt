#include <stdio.h>
#include <stdlib.h>

#include "utils/common.h"

int main(int argc, char **argv) {
	uint64_t a = strtoull(argv[1], NULL, 10),
			 b = strtoull(argv[2], NULL, 10);
	//printf("GCD of %lu and %lu = %ld\n", a, b, tcrypt_bgcd(a, b));
	printf("MI of %lu in Z_%lu is %lu\n", a, b, tcrypt_mi(a, b));
	return 0;
}
