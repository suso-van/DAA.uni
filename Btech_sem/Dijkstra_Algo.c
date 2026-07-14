#include<stdio.h>

#define INF 9999

int main()
{
    int n,i,j,start;
    int cost[10][10];
    int dist[10],visited[10]={0};

    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Enter source: ");
    scanf("%d",&start);

    for(i=0;i<n;i++)
        dist[i]=cost[start][i];

    visited[start]=1;
    dist[start]=0;

    for(i=1;i<n;i++)
    {
        int min=INF,u;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        int k;

        for(k=0;k<n;k++)
        {
            if(!visited[k] && dist[u]+cost[u][k]<dist[k])
                dist[k]=dist[u]+cost[u][k];
        }
    }

    printf("Shortest distances:\n");

    for(i=0;i<n;i++)
        printf("%d -> %d = %d\n",start,i,dist[i]);

    return 0;
}
