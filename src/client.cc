#include <stdio.h>
#include <stdlib.h>
#include <WinSock.h>
#pragma comment(lib, "ws2_32.lib") // load ws2_32.dll
#define BUFSIZE 100

int main()
{
    // initial DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // raise a request to server
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr)); // fill with 0
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(12345);

    char bufSend[BUFSIZE] = {0};
    char bufRecv[BUFSIZE] = {0};

    while (1) {

        SOCKET sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        // SOCKET sock = socket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP);
        connect(sockfd, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

        printf("Please enter a string: ");
        gets(bufSend);
        send(sockfd, bufSend, strlen(bufSend), 0);
        recv(sockfd, bufRecv, BUFSIZE, 0);
        printf("Message from server: %s\n", bufRecv);

        memset(bufSend, 0, BUFSIZE);
        memset(bufRecv, 0, BUFSIZE);

        closesocket(sockfd); // differnent with linux's close()
    }
    WSACleanup(); // end up DLL
    return 0;
}
