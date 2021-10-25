CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -m32
PUBL=publications
HASH=Hashtable
LIST=LinkedList

.PHONY: build clean

build: publications_unlinked.o $(HASH).o $(LIST).o 
	ld -m elf_i386 -r *.o -o $(PUBL).o 

publications_unlinked.o: $(PUBL).c 
	$(CC) $(CFLAGS) $^ -c -o publications_unlinked.o 
$(HASH).o: $(HASH).c 
	$(CC) $(CFLAGS) $^ -c
$(LIST).o: $(LIST).c 
	$(CC) $(CFLAGS) $^ -c
clean:
	rm -f *.o *.h.gch
