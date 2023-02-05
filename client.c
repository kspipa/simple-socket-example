#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "lib.h"
int main(){
    static struct sockaddr_in serv_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5005);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        printf("Cant connect to server\n");
    else
        printf("Connect!\n");
    pack jj;
    jj.neger = "n";
    jj.mm = 2002031002;
    send(sock, &jj, sizeof(jj), 0);
}