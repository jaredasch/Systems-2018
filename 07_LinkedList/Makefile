all:	testing.o linked_list.o
	gcc -o out testing.o linked_list.o

linked_list.o: linked_list.c
	gcc -c linked_list.c

testing.o: testing.c linked_list.h
	gcc -c testing.c

run:
	./out

clean:
	rm out
	rm *.o

