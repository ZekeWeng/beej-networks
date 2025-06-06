#include <stdint.h>      // For uint16_t, uint32_t
#include <arpa/inet.h>   // For byte order conversion functions

// Byte order conversion functions from arpa/inet.h
// These functions convert between host byte order and network byte order
// Network byte order is always big-endian

// Convert 16-bit (short) values
uint16_t htons(uint16_t hostshort);    // Host TO Network Short
uint16_t ntohs(uint16_t netshort);     // Network TO Host Short

// Convert 32-bit (long) values
uint32_t htonl(uint32_t hostlong);     // Host TO Network Long
uint32_t ntohl(uint32_t netlong);      // Network TO Host Long

// Example usage:
// uint16_t port = 80;
// uint16_t network_port = htons(port);  // Convert to network byte order
// uint16_t host_port = ntohs(network_port);  // Convert back to host byte order

// Common use cases:
// 1. Converting port numbers for socket programming
// 2. Converting IP addresses for network transmission
// 3. Converting multi-byte values in network protocols