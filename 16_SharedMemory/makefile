all: sharedmem.o
	gcc -o out sharedmem.o

sharedmem.o: sharedmem.c
	gcc -c sharedmem.c

run:
	./out

clean:
	rm out
	rm *.o
