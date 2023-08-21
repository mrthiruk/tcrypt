#include <stdio.h>
#include <stdlib.h>

#include "utils/common.h"

int main(int argc, char **argv) {
	int64_t a = strtoll(argv[1], NULL, 10),
			 b = strtoll(argv[2], NULL, 10);
	printf("GCD of %ld and %ld = %ld\n", a, b, tcrypt_bgcd(a, b));
	return 0;
}
