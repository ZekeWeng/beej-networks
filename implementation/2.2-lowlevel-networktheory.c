#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Stream socket example (TCP)
int stream_socket = socket(AF_INET, SOCK_STREAM, 0);
send(stream_socket, data, data_len, 0);

// Datagram socket example (UDP)
int datagram_socket = socket(AF_INET, SOCK_DGRAM, 0);
sendto(datagram_socket, data, data_len, 0, (struct sockaddr*)&addr, sizeof(addr));

// No need to manually construct:
// - Ethernet headers
// - IP headers
// - TCP/UDP headers
// - Checksums
// - Packet fragmentation
// - Routing information

