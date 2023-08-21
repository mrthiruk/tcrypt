CC := gcc
CFLAGS := -Wall -Werror -std=c99 -I.. -L../build

test: utils_test.c
	$(CC) $(CFLAGS) -o utils_test.out utils_test.c -ltcrypt-utils
