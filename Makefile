CC := gcc
CFLAGS := -Wall -Werror -std=c99 -I.

SRC_UTILS := utils/common.h utils/common.c utils/types.h

utils: $(SRC_UTILS)
	mkdir build
	$(CC) $(CFLAGS) -o build/common.o -c utils/common.c
	ar rcs build/libtcrypt-utils.a  build/common.o

clean:
	rm -rf build/
