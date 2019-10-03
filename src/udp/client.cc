#include <stdio.h>
#include <WindSock2.h>
#pragma comment(lib, "ws2_32.lib")
#define BUFSIZE 100

// no connect() call here cause of UDP needn't connections.

int main()
{
    WSADATA wsaData;
    WSAStartup (MAKEWORD(2, 2), &wsaData);

    SOCKET sockfd = socket(PF_INET, SOCK_DGRAM, 0);

    sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = PF_INTE;
    serAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // transfer bid endian or little endian
    serAddr.sin_port = htons(12345);

    sockaddr cliAddr;
    int clilen = sizeof(cliAddr);
    while (1) {
        char buf[BUFSIZE] = {0};
        printf("Please enter a string: ");
        gets(buf);
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&serAddr, sizeof(serAddr));
        int len = recvfrom(sockfd, buf, BUFSIZE, 0, &cliAddr, &clilen);
        buf[len] = 0;
        printf("Message from server: %s\n", buf);
    }
    closesocket(sockfd);
    WSACleanup();
    return 0;
}
