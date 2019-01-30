all: main.o sieve.o 
	gcc -o out main.o sieve.o

main.o: main.c
	gcc -c main.c

sieve.o: sieve.c
	gcc -c sieve.c

run:
	./out

clean:
	rm out
	rm *.o