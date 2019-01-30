all: handler.o
	gcc -o out handler.o

handler.o: handler.c
	gcc -c handler.c

run: 
	./out

clean:
	rm out
	rm *.o
	rm error.txt
