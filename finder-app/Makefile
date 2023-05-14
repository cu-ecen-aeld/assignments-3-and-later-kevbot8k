CC=gcc
CC_LIBS := "/home/kevbot/Downloads/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/../aarch64-none-linux-gnu/libc"

all: writer.o writer
writer.o:
	$(CROSS_COMPILE)$(CC) -g -Wall -c -o writer.o writer.c;
writer:
	$(CROSS_COMPILE)$(CC) -g -Wall writer.o -o writer;
clean:
	-rm -f *.o writer *.elf *.map

