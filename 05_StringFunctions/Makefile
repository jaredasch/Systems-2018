all: function_testing.o string_functions.o
	gcc -o out function_testing.o string_functions.o

function_testing.o: function_testing.c string_functions.h
	gcc -c function_testing.c

string_functions.o: string_functions.c
	gcc -c string_functions.c

run:
	./out

clean:
	rm *.o
	rm out
