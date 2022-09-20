#include<stdio.h>
int main()
{
    int dist[25][25],dmat[25][25],via[25][25],n,i,j,k,count;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            dist[i][j]=dmat[i][j];
            via[i][j]=j;
        }
    }
    printf("\nCost Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",dmat[i][j]);
        }
        printf("\n");
    }  
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(dist[i][j]>dmat[i][k]+dist[k][j])
                    {
                        dist[i][j]=dmat[i][k]+dist[k][j];
                        via[i][j]=k;
                        count++;
                    }
                }
            }
        }
    }
    while(count!=0); 
    for(i=0;i<n;i++)
    {
        printf("\nState value of node %d\n",i);
        for(j=0;j<n;j++)
        {
            printf("To %d via %d distance %d\n",j,via[i][j],dist[i][j]);
        }
    }

    return 0;
}