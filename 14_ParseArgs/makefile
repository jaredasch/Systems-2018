all: arguments.o
	gcc -o out arguments.o

arguments.o: arguments.c
	gcc -c arguments.c

run: 
	./out

clean:
	rm out
	rm *.o