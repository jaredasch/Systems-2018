#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){
	printf("Inserting element 3 at the begining of the list\n");
	struct node *list  = insert_front(0, 3);
	print_list(list);

	printf("\nInserting element 2 at the begining of the list\n");
	list = insert_front(list, 2);
	print_list(list);

	printf("\nInserting element 1 at the begining of the list\n");
	list = insert_front(list, 1);
	print_list(list);

	printf("\nfree_list(): %p\n", list = free_list(list));
	printf("List after being freed:\n");
	print_list(list);

	return 0;
}
