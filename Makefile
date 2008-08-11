CC=gcc
CFLAGS=-Wall
LIBS=-lm
TARGETS=mypso
mypso: 
	$(CC) $(CFLAGS) $(LIBS) -o $@ $@.c 

clean:
	rm -f *.o $(TARGETS)  
