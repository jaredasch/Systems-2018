#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
    mkfifo("upstream", 0644);
    printf("(Server) Waiting for client connection to upstream pipe\n");
    int upstream = open("upstream", O_RDONLY);

    char private_pipe_name[HANDSHAKE_BUFFER_SIZE];
    printf("(Server) Preparing to recieve private pipe name...\n");
    read(upstream, private_pipe_name, HANDSHAKE_BUFFER_SIZE);
    remove("upstream");

    printf("(Server) Received private pipe name %s\n", private_pipe_name);
    int downstream = open(private_pipe_name, O_WRONLY);
    write(downstream, ACK, HANDSHAKE_BUFFER_SIZE);
    printf("(Server) Sending acknowledgement message\n");

    char msg[HANDSHAKE_BUFFER_SIZE];
    read(upstream, msg, HANDSHAKE_BUFFER_SIZE);
    printf("(Server) Received acknowledgement message %s from client\n", msg);
    *to_client = downstream;
    return upstream;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
    printf("(Client) Waiting to connect to server on upstream pipe\n");
    int upstream = open("upstream", O_WRONLY);

    char private_pipe_name[HANDSHAKE_BUFFER_SIZE] = "priv_pipe";
    mkfifo(private_pipe_name, 0644);

    printf("(Client) Creating private pipe with name %s\n", private_pipe_name);

    write(upstream, private_pipe_name, HANDSHAKE_BUFFER_SIZE);
    printf("(Client) Sent private pipe name \"%s\" to server...waiting for server connection to private pipe\n", private_pipe_name);
    int downstream = open(private_pipe_name, O_RDONLY);

    printf("(Client) Waiting for acknowledgement from server...\n");
    char msg[HANDSHAKE_BUFFER_SIZE];
    read(downstream, msg, HANDSHAKE_BUFFER_SIZE);
    printf("(Client) Received acknowledgement message %s from server\n", msg);

    printf("(Client) Sending acknowledgement message %s back to server\n", msg);
    write(upstream, msg, HANDSHAKE_BUFFER_SIZE);

    remove(private_pipe_name);
    *to_server = upstream;
    return downstream;
}
