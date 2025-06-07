#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void print_ipv4_info(const char *ip_str) {
    struct in_addr addr;
    char ip_str_out[INET_ADDRSTRLEN];

    if (inet_pton(AF_INET, ip_str, &addr) != 1) {
        printf("Invalid IPv4 address: %s\n", ip_str);
        return;
    }

    inet_ntop(AF_INET, &addr, ip_str_out, INET_ADDRSTRLEN);

    printf("IPv4 Address: %s\n", ip_str_out);
    printf("Network Byte Order: %u\n", addr.s_addr);
    printf("Host Byte Order: %u\n", ntohl(addr.s_addr));
}

void print_ipv6_info(const char *ip_str) {
    struct in6_addr addr;
    char ip_str_out[INET6_ADDRSTRLEN];

    if (inet_pton(AF_INET6, ip_str, &addr) != 1) {
        printf("Invalid IPv6 address: %s\n", ip_str);
        return;
    }

    inet_ntop(AF_INET6, &addr, ip_str_out, INET6_ADDRSTRLEN);

    printf("IPv6 Address: %s\n", ip_str_out);
}

int is_private_ipv4(const char *ip_str) {
    struct in_addr addr;
    uint32_t ip;

    if (inet_pton(AF_INET, ip_str, &addr) != 1) {
        return 0;
    }

    ip = ntohl(addr.s_addr);

    if ((ip >= 0x0A000000 && ip <= 0x0AFFFFFF) ||  // 10.0.0.0/8
        (ip >= 0xAC100000 && ip <= 0xAC1FFFFF) ||  // 172.16.0.0/12
        (ip >= 0xC0A80000 && ip <= 0xC0A8FFFF)) {  // 192.168.0.0/16
        return 1;
    }

    return 0;
}

int main() {
    printf("Example 1: IPv4 Address Conversion\n");
    printf("--------------------------------\n");
    print_ipv4_info("192.168.1.1");
    printf("\n");

    printf("Example 2: IPv6 Address Conversion\n");
    printf("--------------------------------\n");
    print_ipv6_info("2001:db8::1");
    printf("\n");
    
    printf("Example 3: Private IP Detection\n");
    printf("--------------------------------\n");
    const char *test_ips[] = {
        "10.0.0.1",
        "172.16.0.1",
        "192.168.1.1",
        "8.8.8.8"
    };

    for (int i = 0; i < 4; i++) {
        printf("IP: %s is %s\n",
               test_ips[i],
               is_private_ipv4(test_ips[i]) ? "private" : "public");
    }

    return 0;
}