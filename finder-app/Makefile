CC=gcc
CC_LIBS := "/home/kevbot/Downloads/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/../aarch64-none-linux-gnu/libc"

compile:
	$(CROSS_COMPILE)gcc -g -Wall -c -o writer.o writer.c;
executable:
	if [ -z "$(CROSS_COMPILE)" & "$(CROSS_COMPILE)" == "aarch64-none-linux-gnu-"]; then \
	$(CROSS_COMPILE)gcc -g -Wall -I$(CC_LIBS) writer.o -o writer; \
	else \
	gcc -g -Wall writer.o -o writer; \
	fi


clean:
	-rm -f *.o writer *.elf *.map

all: clean compile executable
