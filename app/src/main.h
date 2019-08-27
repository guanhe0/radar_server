#ifndef RADAR_INC_MAIN_H
#define RADAR_INC_MAIN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#define PORT 1314
#define QLEN 10
#define BUFSIZE 1024
void sig_chld(int);
class ProcessCli{
    public:
    void process_cli(int connectfd,sockaddr_in,client);
};
class ServerObj{
    public:
    int listenfd,connectfd;
    pid_t pid;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t ssize;
    int opt;
    public:
    void InitServerAddr();
    int CreateMasterSocket();
};

#endif

