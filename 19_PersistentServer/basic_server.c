#include "pipe_networking.h"

static void sighandler(int signo){
    if(signo == SIGINT){
        printf("Removing WKP....");
        remove("upstream");
        printf("Done\n");
        exit(1);
    }
}

int main() {
    int to_client;
    int from_client;
    signal(SIGINT, sighandler);

    while(1){
        from_client = server_handshake( &to_client );
        char data[BUFFER_SIZE];
        while(read(from_client, data, BUFFER_SIZE)){
            printf("Recieved \"%s\" from client\n", data);

            // Transform text
            for(char * d = data; *d; d++){
                (*d)++;
            }

            printf("Sent \"%s\" back to client\n", data);
            write(to_client, data, BUFFER_SIZE);
        }
    }
}
