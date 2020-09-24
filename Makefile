CC=gcc
CFLAGS=-Wall -pedantic -std=c99
IN=$(wildcard src/*.c)
OUT=target/riego 

all: $(OUT)

target/riego: ${IN}
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OUT)
	
.PHONY: all	clean
