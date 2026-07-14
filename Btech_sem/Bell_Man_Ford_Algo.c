#include <stdio.h>

#define INF 9999

int main()
{
    int V, E, i, j;
    int u[20], v[20], w[20];
    int dist[20];

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &V, &E);

    printf("Enter edges (u, v, weight):\n");
    for(i = 0; i < E; i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);

    int source = 0;

    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(i = 1; i < V; i++)
    {
        for(j = 0; j < E; j++)
        {
            if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                dist[v[j]] = dist[u[j]] + w[j];
        }
    }

    printf("Distances from source:\n");
    for(i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}
