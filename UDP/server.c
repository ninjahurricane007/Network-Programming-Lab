#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<netdb.h>
#include<netinet/in.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080
#define MAX 80
#define SA struct sockaddr

int main()
{
    int sockfd,len;
    struct sockaddr_in servaddr,cliaddr;
    char buffer[MAX];
    char msg[MAX]="Hello from server";

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd>=0)
    {
        printf("\nSocket Created");
    }

    bzero(&servaddr,sizeof(servaddr));
    bzero(&cliaddr,sizeof(cliaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(sockfd,(SA*)&servaddr,sizeof(servaddr))==0)
    {
        printf("\nSocket Binded");
    }
    
    len=sizeof(cliaddr);
    recvfrom(sockfd,buffer,MAX,MSG_WAITALL,(SA*)&cliaddr,&len);
    printf("\nFrom Client: %s\n",buffer);
    sendto(sockfd,msg,MAX,MSG_CONFIRM,(SA*)&cliaddr,sizeof(cliaddr));

    close(sockfd);

    return 0;
}
