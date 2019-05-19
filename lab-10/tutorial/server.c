/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen; // size of address of the client
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n; // return value for rade() and write()

  // example: ./server 12345, where 12345 is port number
  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  // AF_UNIX|AF_INET, SOCK_STREAM|SOCK_DGRAM, protocol (almost every time it
  // should be 0, system should choose protocol for us)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  // sets all values in buffer to zero
  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // binds a socket to an address, in this case address of current host and port
  // number on which the server will run

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  // listen on the socket for connections
  // first arg: socket file descriptor
  // second arg: number of connections that can be waiting while the process
  //             handling a particular connection
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  // blocks the process until client connects to the server
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (newsockfd < 0)
    error("ERROR on accept");

  bzero(buffer, 256);
  n = read(newsockfd, buffer, 255);
  if (n < 0)
    error("ERROR reading from socket");
  printf("Here is the message: %s\n", buffer);
  n = write(newsockfd, "I got your message", 18);
  if (n < 0)
    error("ERROR writing to socket");
  close(newsockfd);
  close(sockfd);
  return 0;
}
