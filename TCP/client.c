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

void msg(int sockfd)
{
    char buffer[MAX];
    for(;;)
    {
        bzero(buffer,MAX);
        printf("\nTo Server: ");
        fgets(buffer,MAX,stdin);
        write(sockfd,buffer,MAX);
        read(sockfd,buffer,MAX);
        printf("\nFrom Server: %s",buffer);
        if(strncmp("exit",buffer,4)==0)
        {
            printf("\nClient exited");
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
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))==0)
    {
        printf("\nConnected to Server");
    }

    msg(sockfd);
    close(sockfd);

    return 0;
}