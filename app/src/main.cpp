#include<iostream> 
#include "main.h"

int ServerObj::CreateMasterSocket()
{
    listenfd = socket(AF_INET,SOCK_STREAM,0); 
    return listenfd;
}
void ServerObj::InitServerAddr()
{
    opt = SO_REUSEADDR;
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
}
int main()
{
    return 0;    	    
}
