#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
#include <unistd.h>

#include "hdr/msgHeader.h"

#define SIZE    sizeof(struct sockaddr_in)
#define MAX_SIZE    2048

void *recvmsg(void *params);
int sendMsg(char *msg, int size, char *ip, int port);
int sendMsg2(char *msg, int size, struct sockaddr* sock, int sock_len);

int main() {

    pthread_t tid;
    if(pthread_create(&tid, NULL, recvMsg, NULL)) {
        printf("thread create fail\n");
    }

    struct msgEnv mEnv;
    mEnv.hdr.cmdId = reqSetEnv;
    strcpy(mEnv.env.envName, "TESTENV");
    strcpy(mEnv.env.Value, "");
    write(mEnv);
    sendMsg((char *)&mEnv, sizeof(mEnv), (char*)"127.0.0.1", PORT_SERVER_R);

    while(1)
        sleep(1);
}

void *recvMsg(void *params) {
    struct sockaddr_in mySock = {AF_INET, htons(PORT_CLIENT_R), INADDR_ANY};
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int ret = bind(sockfd, (struct sockaddr *)&mySock, sizeof(mySock));
    if(ret<0) {
        extern int errno;
        printf("ret(%d), errno(%d. %s)\n", ret, errno, strerror(errno));
    }

    struct sockaddr_in sock;
    int sock_len;
    char msg[MAX_SIZE];
    while(1) {
        memset(meg, 0, MAX_SIZE);
        int ret = recvfrom(sockfd, &msg, MAX_SIZE, 0 (struct sockaddr *)&sock, (socklen_t *)&sock_len);
    }
}


