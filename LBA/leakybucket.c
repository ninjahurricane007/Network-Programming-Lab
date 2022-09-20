#include<stdio.h>
int main()
{
    int incoming,outgoing,bucksize,n,store=0;
    printf("\nEnter the bucket size, outgoing rate and no. of inputs: ");
    scanf("%d%d%d",&bucksize,&outgoing,&n);
    while(n!=0)
    {
        printf("\nEnter the size of incoming packet: ");
        scanf("%d",&incoming);
        if(incoming<=bucksize-store)
        {
            store=store+incoming;
            printf("Bucket buffer size %d out of %d\n",store,bucksize);
        }
        else
        {
            printf("Dropped %d packets\n",incoming-(bucksize-store));
            store=bucksize;
            printf("Bucket buffer size %d out of %d\n",store,bucksize);
        }
        if(outgoing>store)
        {
            store=0;
        }
        else
        {
            store=store-outgoing;
            printf("After outgoing %d packets left out of %d\n",store,bucksize);
        }
        n--;
    }
    return 0;
}