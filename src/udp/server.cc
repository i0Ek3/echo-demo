#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define BUFSIZE 100


// no listen() call here, just need socket()/bind()/recvfrom()/sendto() call here.

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = PF_INET;
    serAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serAddr.sin_port = htons(12345);
    bind(sockfd, (SOCKADDR*)&serAddr, sizeof(SOCKADDR));

    SOCKADDR cliAddr;
    int size = sizeof(SOCKADDR);
    char buf[BUFSIZE];
    while (1) {
        int len = recvfrom(sockfd, buf, BUFSIZE, 0, &cliAddr, &size);
        sendto(sockfd, buf, len, 0, &cliAddr, size);
    }
    closesocket(sockfd);
    WSACleanup();
    return 0;
}
