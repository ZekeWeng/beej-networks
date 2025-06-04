#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// Structure to hold an IPv4 address
typedef struct {
    uint8_t octets[4];
} IPv4Address;

// Structure to hold an IPv6 address
typedef struct {
    uint16_t groups[8];
} IPv6Address;

// Function to print IPv4 address
void print_ipv4(IPv4Address addr) {
    printf("%d.%d.%d.%d\n",
           addr.octets[0],
           addr.octets[1],
           addr.octets[2],
           addr.octets[3]);
}

// Function to print IPv6 address
void print_ipv6(IPv6Address addr) {
    printf("%x:%x:%x:%x:%x:%x:%x:%x\n",
           addr.groups[0], addr.groups[1], addr.groups[2], addr.groups[3],
           addr.groups[4], addr.groups[5], addr.groups[6], addr.groups[7]);
}

// Function to demonstrate subnet mask
void demonstrate_subnet(uint32_t ip, uint32_t mask) {
    uint32_t network = ip & mask;
    printf("IP: %u.%u.%u.%u\n",
           (ip >> 24) & 0xFF,
           (ip >> 16) & 0xFF,
           (ip >> 8) & 0xFF,
           ip & 0xFF);
    printf("Network: %u.%u.%u.%u\n",
           (network >> 24) & 0xFF,
           (network >> 16) & 0xFF,
           (network >> 8) & 0xFF,
           network & 0xFF);
}
