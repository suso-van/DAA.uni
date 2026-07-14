#include <stdio.h>

int graph[10][10];
int visit[10];
int queue[10];
int front=-1,rear=-1;

void BFS(int n,int s){
    visit[s]=1;
    front=rear=0;
    queue[rear]=s;
    
    while(front<=rear){
        int c= queue[front];
        front++;
        
        printf("%d ",c); 
        for(int i=0;i<n;i++){
            if(graph[c][i]==1 && visit[i]==0){
                visit[i]=1; 
                rear++;
                queue[rear]=i;
            }
        }
    }
}

int main() {
    int n,i,j,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    printf("Start vertex: ");
    scanf("%d",&s);

    BFS(n,s);

    return 0;
}
