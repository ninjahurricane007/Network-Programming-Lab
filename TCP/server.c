#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<arpa/inet.h>

#include<netdb.h>
#include<netinet/in.h>

#include<sys/socket.h>
#include<sys/types.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void msg(int confd)
{
    char buffer[MAX];
    for(;;)
    {
        bzero(buffer,MAX);
        read(confd,buffer,MAX);
        printf("\nFrom Client: %s",buffer);
        printf("\nTo Client: ");
        fgets(buffer,MAX,stdin);
        write(confd,buffer,MAX);
        if(strncmp("exit",buffer,4)==0)
        {
            printf("\nServer exited");
            break;
        }
    }
    
}

int main()
{
    int sockfd,confd,len;
    struct sockaddr_in cliaddr,servaddr;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd>=0)
    {
        printf("\nSocket Created");
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(sockfd,(SA*)&servaddr,sizeof(servaddr))==0)
    {
        printf("\nSocket Binded");
    }

    if(listen(sockfd,5)==0)
    {
        printf("\nListening...");
    }

    len=sizeof(cliaddr);
    confd=accept(sockfd,(SA*)&cliaddr,&len);
    if(confd>=0)
    {
        printf("\nConnection Accepted");
    }

    msg(confd);
    close(sockfd);

    return 0;
}