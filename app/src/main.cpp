#include<iostream> 
#include "main.h"

int ServerObj::CreateMasterSocket()
{
    listenfd = socket(AF_INET,SOCK_STREAM,0); 
    return listenfd;
}
int main()
{
    return 0;    	    
}
