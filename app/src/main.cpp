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
	socklen_t ssize;
	ssize = sizeof(struct sockaddr_in);
	signal(SIGCHLD,sig_chld);
	while(1){
		if((connectfd = accept(listenfd,(struct sockaddr_in *)&client,&ssize)) == -1){
			perror("accept() error\n");
			exit(1);
		}
		if((pid = fork())>0){
			close(connectfd);			
			continue;
		}
		else if(pid == 0){
			close(listenfd);
			process_cli(connectfd,client);
			exit(0);
		}
		else{
			printf("fork error\n");
			exit(0);
		}
	}
	close(listenfd);
    return 0;    	    
}

void process_cli(int connectfd,sockaddr_in client)
{
	int num;
	char  recvbuf[BUFSIZE],sendbuf[BUFSIZE],cli_name[BUFSIZE];
	int len;
	printf("You got a connection from %s",inet_ntoa(client.sin_addr));
	
	num = recv(connectfd,cli_name,BUFSIZE,0);
	
	if(num == 0){
		close(connectfd);
		printf("Client disconnected.\n");
		return;
	}
	cli_name[num-1] = '\0';
	printf("Client's name is %s. \n",cli_name);
	while(num = recv(connectfd,recvbuf,BUFSIZE,0)){
		recvbuf[num] = '\0';
		printf("Received client (%s) message:%s",cli_name,recvbuf);
		for(int i = 0; i < num - 1; i++){
			sendbuf[i] = recvbuf[num - i - 2];
		}
		sendbuf[num-1] = '\0';
		len = strlen(sendbuf);
		send(connectfd,sendbuf,len,0);
	}
	close(connectfd);
}

void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	while((pid = waitpid(-1,&stat,WNOHANG))>0);
	printf("child %d terminated\n",pid);	
	return;
}