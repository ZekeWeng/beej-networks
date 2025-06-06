#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void print_ipv4(struct sockaddr_in *addr) {
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr->sin_addr), ipstr, INET_ADDRSTRLEN);
    printf("IPv4 Address: %s\n", ipstr);
    printf("Port: %d\n", ntohs(addr->sin_port));
}

void print_ipv6(struct sockaddr_in6 *addr) {
    char ipstr[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &(addr->sin6_addr), ipstr, INET6_ADDRSTRLEN);
    printf("IPv6 Address: %s\n", ipstr);
    printf("Port: %d\n", ntohs(addr->sin6_port));
}
