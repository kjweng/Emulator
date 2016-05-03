CC=clang
CFLAGS=-Wall -g
LD=clang
LDFLAGS=-g

OBJS1=cpu_i8080.o
OBJS2=test.o
SRC1=cpu_i8080.c
SRC2=test.c
TEST=test

all: $(OBJS1) $(TEST)

$(TEST): $(OBJS2)
	$(LD) $(LDFLAGS) -o $@ $(OBJS1) $(OBJS2)

$(OBJS1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) 

$(OBJS2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2)

.PHONY: clean
clean:
	rm -f *.o *.out $(TEST)


