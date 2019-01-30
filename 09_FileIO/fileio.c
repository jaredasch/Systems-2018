#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char *buffer = calloc(1, 100);
    printf("Initializing empty char buffer at %p\n", buffer);
    int fd_in = open("input", O_RDONLY);
    printf("New file descriptor %d for input\n", fd_in);
    int size = read(fd_in, buffer, 100);
    printf("Reading from input file into buffer...\n");
    close(fd_in);

    printf("Buffer: %s\n", buffer);

    int fd_out = open("output", O_CREAT | O_RDWR);
    printf("New file descriptor %d for output\n", fd_out);
    write(fd_out, buffer, 100);
    printf("Writing from buffer to output file...\n");
    close(fd_out);
    printf("Freeing buffer and closing files\n");
    free(buffer);
    return 0;
}
