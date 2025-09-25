#include <stdio.h>

#define MAX 10  

int visited[MAX];        
int graph[MAX][MAX];     // adjacency matrix
int n;                   


void DFS(int vertex) {
    printf("%d ", vertex);   // print the current vertex
    visited[vertex] = 1;     // mark as visited

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);  // recursive call
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize graph with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   // if undirected graph
    }

    printf("DFS traversal starting from node 0: ");
    DFS(0);

    return 0;
}
