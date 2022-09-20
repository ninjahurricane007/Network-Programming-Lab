#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<unistd.h>
#include<arpa/inet.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netdb.h>
#include<netinet/in.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int main()
{
    int sockfd,confd,len,n=0;
    struct sockaddr_in servaddr,cliaddr;
    char buffer[MAX];
    char filename[MAX];

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd>=0)
    {
        printf("\nSocket Created");
    }

    bzero(&servaddr,sizeof(servaddr));
    bzero(&cliaddr,sizeof(cliaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))==0)
    {
        printf("\nConnected to server");
    }

    printf("\nEnter the filename: ");
    scanf("%s",filename);
    write(sockfd,filename,MAX);
    read(sockfd,buffer,MAX);
    printf("\nFile Contents: %s\n",buffer);

    close(sockfd);

    return 0;
}