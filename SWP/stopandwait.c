#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>

struct frame
{
    int data;
    char ack;
}frm[10];

int main()
{
    int i,n,r;
    printf("\nEnter the number of packets to be sent: ");
    scanf("%d",&n);
    printf("\nEnter the data for each packet:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&frm[i].data);
        frm[i].ack='y';
    }
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
    printf("Resending packet %d...",r);
    sleep(2);
    frm[r].ack='y';
    printf("\nPacket %d with data %d received",r,frm[r].data);
    printf("\nAll packets sent successfully\n");
}