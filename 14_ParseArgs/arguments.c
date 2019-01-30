#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args( char * line ){
	char ** arglist = calloc(sizeof(char*), 25); // 25 args max
	for(int i = 0; (arglist[i] = strsep(&line, " ")); i++);
	return arglist;
}

int main(){
	char s0[50] = "ls -l -a -b -c";
	printf("Printings args for %s\n", s0);
	char ** args0 = parse_args(s0);
	while(*args0){
		printf("%s\n", *(args0++));
	}

	char s1[50] = "ls";
	printf("\nPrintings args for %s\n", s1);
	char ** args1 = parse_args(s1);
	while(*args1){
		printf("%s\n", *(args1++));
	}
	
	return 0;
}