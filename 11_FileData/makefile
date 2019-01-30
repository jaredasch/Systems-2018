all: file_stats.o
	gcc -o out file_stats.o

file_stats.o: file_stats.c
	gcc -c file_stats.c

clean:
	rm out
	rm *.o

run: 
	./out