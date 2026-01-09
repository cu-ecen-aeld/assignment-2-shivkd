# Set cross compilier and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Werror -g
LDFLAGS ?=
#build default targert
all: writer
#build executable
writer: writer.o
	$(CC) $(CFLAGS) -o writer writer.o $(LDFLAGS)
writer.o: writer.c
	$(CC) $(CFLAGS) -c  writer.c

clean: 
	rm -f writer *.o

.PHONY: all clean
