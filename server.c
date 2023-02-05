#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "lib.h"

static int sock = 0, neg = 0;
static char buffer[8192] = { 0 };
int main(){
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Cant create socket\n");
    else
        printf("Socket has been created\n");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5005);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind(sock, (struct sockaddr *)&addr, sizeof(addr))) < 0)
        printf("Cant bind socket\n");
    else
        printf("Socket has been binded\n");
    if ((listen(sock, 10)) < 0)
        printf("Socket cant listen\n");
    else
        printf("Socket listen\n");
    while(1){
        neg = accept(sock,(struct sockaddr*)NULL, NULL);
        read(neg, buffer, 8192);
        pack *tt = (pack*)&buffer;
        printf("%c\n", tt->neger);
        printf("Get some packets\n");
    }
}