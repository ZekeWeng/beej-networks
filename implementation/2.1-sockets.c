#include <sys/types.h>    // For ssize_t, size_t
#include <sys/socket.h>   // For socket functions

// Socket types
#define SOCK_STREAM 1    // Reliable, connection-oriented socket (TCP)
#define SOCK_DGRAM  2    // Unreliable, connectionless socket (UDP)

// Socket creation and connection
int socket(int domain, int type, int protocol);  // Creates a new socket
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);  // Connects socket to address

// Data transfer functions, former provide greater control over the socket
ssize_t send(int sockfd, const void *buf, size_t len, int flags);    // Send data through socket
ssize_t recv(int sockfd, void *buf, size_t len, int flags);          // Receive data from socket
ssize_t write(int sockfd, const void *buf, size_t len);              // Write data to socket
ssize_t read(int sockfd, void *buf, size_t len);                     // Read data from socket
