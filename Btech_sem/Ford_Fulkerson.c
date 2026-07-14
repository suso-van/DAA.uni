#include<stdio.h>

int graph[10][10], visited[10];
int n;

int dfs(int s,int t,int flow)
{
    if(s==t)
        return flow;

    visited[s]=1;

    int i;

    for(i=0;i<n;i++)
    {
        if(!visited[i] && graph[s][i]>0)
        {
            int minflow=flow;

            if(graph[s][i]<minflow)
                minflow=graph[s][i];

            int result=dfs(i,t,minflow);

            if(result>0)
            {
                graph[s][i]-=result;
                graph[i][s]+=result;
                return result;
            }
        }
    }

    return 0;
}

int main()
{
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int source,sink;

    scanf("%d%d",&source,&sink);

    int maxflow=0;

    while(1)
    {
        for(i=0;i<n;i++)
            visited[i]=0;

        int flow=dfs(source,sink,9999);

        if(flow==0)
            break;

        maxflow+=flow;
    }

    printf("Maximum Flow=%d",maxflow);

    return 0;
}
