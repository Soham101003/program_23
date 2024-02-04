/*simple program that takes in a domain name and 
resolves the corresponding IPv4 and IPv6 addresses.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

typedef int (*AddressResolver)(const char *hostname, struct addrinfo **result);

int resolveIPv4(const char *hostname, struct addrinfo **result) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    return getaddrinfo(hostname, NULL, &hints, result);
}

int resolveIPv6(const char *hostname, struct addrinfo **result) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET6;
    return getaddrinfo(hostname, NULL, &hints, result);
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize Winsock.\n");
        return 1;
    }

    char domain_name[256];
    printf("Enter domain name: ");
    scanf("%255s", domain_name);

    struct addrinfo *ipv4_result = NULL;
    struct addrinfo *ipv6_result = NULL;

    AddressResolver resolvers[2] = {resolveIPv4, resolveIPv6};
    const char *address_types[2] = {"IPv4", "IPv6"};

    for (int i = 0; i < 2; i++) {
        int ret = resolvers[i](domain_name, i == 0 ? &ipv4_result : &ipv6_result);
        if (ret != 0) {
            fprintf(stderr, "Error: Unable to resolve %s address\n", address_types[i]);
            continue;
        }

        struct addrinfo *p;
        char ip_address[INET6_ADDRSTRLEN];

        for (p = (i == 0 ? ipv4_result : ipv6_result); p != NULL; p = p->ai_next) {
            void *addr;
            if (p->ai_family == AF_INET) {
                struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                addr = &(ipv4->sin_addr);
            } else {
                struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
                addr = &(ipv6->sin6_addr);
            }

            // Updated header inclusion for inet_ntop
            char ip_address[INET6_ADDRSTRLEN];
            inet_ntop(p->ai_family, addr, ip_address, sizeof(ip_address));
            printf("%s address: %s\n", address_types[i], ip_address);
        }

        freeaddrinfo(i == 0 ? ipv4_result : ipv6_result);
    }

    WSACleanup();

    return 0;
}
