CC=gcc
CFLAGS=-Wall
LIBS=-lm 
TARGETS=psond pso1d

psond: randvar.o
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@ $@.c 
	./psond

pso1d: 
	$(CC) $(CFLAGS) $(LIBS) -o $@ $@.c 

clean:
	rm -f *.o $(TARGETS) 

.PHONY: clean
