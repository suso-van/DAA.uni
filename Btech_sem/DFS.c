
#include <stdio.h>

int graph[10][10];
int visit[10];

void DFS(int n, int s) {
    visit[s] = 1;
    printf("%d ", s);
    for(int i = 0; i < n; i++) {
        if(graph[s][i] == 1 && visit[i] == 0) {
            DFS(n, i);
        }
    }
}

int main() {
    int n, i, j, s;

    printf("Enter vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Start: ");
    scanf("%d", &s);

    DFS(n, s);

    return 0;
}
