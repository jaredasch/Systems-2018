#include "pipe_networking.h"
#include <string.h>

int main() {
    int to_server;
    int from_server;

    from_server = client_handshake( &to_server );
    while(1){
        char * buffer = calloc(BUFFER_SIZE, sizeof(char *));
        printf("Enter a message to send to the server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        write(to_server, buffer, BUFFER_SIZE);
        read(from_server, buffer, BUFFER_SIZE);

        printf("Received %s back from server\n", buffer);
    }
}
