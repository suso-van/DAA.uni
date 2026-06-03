#include <stdio.h>

int minDistance(int dist[], int sptSet[], int V)
{
    int min = 999, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int V, int graph[V][V], int src)
{
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = 999, sptSet[i] = 0;
    dist[src] = 0;

    printf("\n=== Initial State ===\n");
    printSolution(dist, V);

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1; 
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != 999 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];{
        }
        printSolution(dist, V);
    }
}

int main()
{
    int V, src;
    printf("Dijkstra's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(V, graph, src);
    return 0;
}
