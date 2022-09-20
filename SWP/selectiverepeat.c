#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>

struct frame
{
    int data;
    char ack;
}frm[10];

int i,n,r;

int send()
{
    printf("\nEnter the number of packets to be sent: ");
    scanf("%d",&n);
    printf("\nEnter the data for each packet:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&frm[i].data);
        frm[i].ack='y';
    }
}

int recvack()
{
    rand();
    r=rand()%n;
    frm[r].ack='n';
    for(i=1;i<=n;i++)
    {
        if(frm[i].ack=='n')
        {
            printf("Packet %d not received\n",i);
        }
    }
}
    
int resend()
{
    printf("Resending packet %d...",r);
    sleep(2);
    frm[r].ack='y';
    printf("\nPacket %d with data %d received",r,frm[r].data);
}
    
int main()
{
    send();
    recvack();
    resend();
    printf("\nAll packets sent successfully\n");
}