#include <stdio.h>
#include <stdlib.h>

struct node { 
	int i; 
	struct node *next; 
};

void print_list(struct node *n){
	while(n){
		printf("%d -> %p\n", n->i, n->next);
		n = n->next;
	}
}

struct node * insert_front(struct node *n, int i){
	struct node *s = malloc(sizeof(struct node));
	s->next = n;
	s->i = i;
	return s;
}

struct node * free_list(struct node *n){
	while(n){
		struct node *p = n->next;
		free(n);
		n = p;
	}
	return n;
};