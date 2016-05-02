CC=clang
CFLAGS=-Wall -g
LD=clang
LDFLAGS=

OBJS1=cpu_i8080.o
OBJS2=test.o
SRC1=cpu_i8080.c
SRC2=test.c
TEST=test

all: test

$(OBJS1): $(SRC1) cpu_i8080.h 
	$(CC) $(CFLAGS) -c $(SRC1) 

$(OBJS2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2)

$(TEST): $(OBJS2) 
	$(LD) $(LDFLAGS) -o $@ $(OBJS2) 



.PHONY: clean
clean:
	rm -f *.o *.out all


