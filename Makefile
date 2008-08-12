CC=gcc
CFLAGS=-Wall
LIBS=-lm
TARGETS=psond pso1d

psond:
	$(CC) $(CFLAGS) $(LIBS) -o $@ $@.c 

pso1d: 
	$(CC) $(CFLAGS) $(LIBS) -o $@ $@.c 

clean:
	rm -f *.o $(TARGETS)  
