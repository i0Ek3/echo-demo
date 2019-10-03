#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define BUFSIZE 100

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0); // this one can be marked up uniquely by TCP, so use 0

    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(12345);
    bind(sockfd, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    listen(sockfd, 20);

    // recive requests from client
    SOCKADDR cliAddr;
    int size = sizeof(SOCKADDR);
    SOCKET clifd = accept(sockfd, (SOCKADDR*)&cliAddr, &size);
    char buf[BUFSIZE];
    int len = recv(clifd, buf, BUFSIZE, 0);
    send(clifd, buf, len, 0);

    // close fd
    closesocket(clifd);
    closesocket(sockfd);
    WSACleanup();
    return 0;
}
