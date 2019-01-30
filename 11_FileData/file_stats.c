#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	struct stat *s = malloc(sizeof(struct stat));
	stat("./file_stats.c", s);

	printf("Size of file: %lld B\n", s->st_size);
	printf("Size of file: %.3f KB\n", s->st_size/1e3);
	printf("Size of file: %.3f MB\n", s->st_size/1e6);

	printf("Mode of file: %o\n", s->st_mode);
	printf("Last access time: %s\n", ctime( &(s->st_atime) ));
	printf("Last modification time: %s\n", ctime( &(s->st_mtime) ));

	char *perms = malloc(10);
	perms[9] = 0;
	for(int i = 0; i < 9; i += 3){
		perms[6 - i] = (s->st_mode >> (2 + i)) % 2 ? 'r' : '-';
		perms[7 - i] = (s->st_mode >> (1 + i)) % 2 ? 'w' : '-';
		perms[8 - i] = (s->st_mode >> (0 + i)) % 2 ? 'x' : '-';
	}
	printf("%s, expecting to be the correct representation of %o\n", perms, s->st_mode);

	return 0;
}