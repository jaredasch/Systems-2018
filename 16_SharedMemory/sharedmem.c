#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(){
    int key = ftok(".", 0);
    int shmid = shmget(key, 1000, IPC_CREAT | 0666);
    // printf("shmid = %d\n", shmid);
    char * buffer = shmat(shmid, (void *) 0, 0);
    if((int) buffer == -1){
        printf("Error: %s\n", strerror(errno));
    }
    
    printf("Initial value of shared memory segment: %s\n", buffer);
    printf("Would you like to change the value stored in memory? (y/n): ");
    char * response_buffer = malloc(2);
    fgets(response_buffer, 10, stdin);

    if(*response_buffer == 'y'){
        printf("Enter a new string to write to shared memory: ");
        fgets(buffer, 200, stdin);
    }

    printf("Would you like to delete the shared memory segment? (y/n): ");
    response_buffer = malloc(2);
    fgets(response_buffer, 10, stdin);

    if(*response_buffer == 'y'){
        shmctl(shmid, IPC_RMID, NULL);
        printf("Detaching and deleting shared memory segment\n");
    }

    return 0;
}
