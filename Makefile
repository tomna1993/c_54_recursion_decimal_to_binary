CC := gcc
#CFLAGS := 
DEST := ./build/

all: recursion_decimal_to_binary.c
	mkdir -p build
	$(CC) recursion_decimal_to_binary.c -lcs50 -o $(DEST)/recursion_decimal_to_binary 