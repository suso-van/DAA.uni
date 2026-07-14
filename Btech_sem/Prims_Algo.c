#include<stdio.h>

#define INF 9999

int main()
{
    int n,i,j;
    int cost[10][10];
    int visited[10]={0};

    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    visited[0]=1;

    int edges=0,total=0;

    while(edges<n-1)
    {
        int min=INF;
        int a,b;

        for(i=0;i<n;i++)
        {
            if(visited[i])
            {
                for(j=0;j<n;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n",a,b,min);

        total+=min;

        visited[b]=1;

        edges++;
    }

    printf("Minimum Cost=%d",total);

    return 0;
}
