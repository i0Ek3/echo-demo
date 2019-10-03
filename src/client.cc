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

    SOCKET sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // SOCKET sock = socket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP);

    // raise a request to server
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr)); // fill with 0
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(12345);
    connet(sockfd, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    // fetch input then send to server
    char bufSend[BUFSIZE] = {0};
    printf("Please enter a string: ");
    gets("%s", bufSend);
    send(sockfd, bufSend, strlen(bufSend), 0);

    // recive data from server
    char bufRecv[BUFSIZE] = {0};
    recv(sockfd, bufRecv, BUFSIZE, 0);

    printf("Message from server: %s\n", bufRecv);
    closesocket(sockfd); // differnent with linux's close()
    WSACleanup(); // end up DLL
    system("pause");
    return 0;
}
