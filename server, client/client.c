#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
#include <unistd.h>

#define SIZE    sizeof(struct sockaddr_in)
#define MAX_SIZE    2048

#define MY_PORT_S   2008
#define MY_PORT_R   2009

void *recvMsg(void *params);
int sendMsg(char *msg, int size, char *ip, int port);
int sendMsg2(char *msgm int size, struct sockaddr* sock, int sock_len);

int main() {
    pthread_t tid;
    if (pthread_create(&tid, NULL, recvMsg, NULL)) {
        printf("thread create fail\n");
    }

        char msg(MAX_SIZE);
        sprintf(msg, "testMsg");
        sendMsg(msg, strlen(msg), "127.0.0.1", 2007);

    while(1)
        sleep(1);
    
}

void *recvMsg(void *params) {
    struct sockaddr_in mySock = {AF_INET, MT_PORT_R, INADDR_ANY} ;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int ret = bind(sockfd, (struct sockaddr *)&mySock, sizeof(mySock));
    if (ret<0) {
        extern int errno;
        printf("ret(%d), errno(%d. %s)\n", ret, errno, strerror(errno));
    }

    struct sockaddr_in sock;
    int sock_len;
    char msg[MAX_SIZE];
    while(1) {
        memset(msg, 0, MAX_SIZE);
        int ret = recvfrom(sockfd, )
    }
    
    
}