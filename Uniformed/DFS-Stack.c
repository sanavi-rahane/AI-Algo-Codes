#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];   
int visited[MAX];     
int stack[MAX];        
int top = -1;          
int n;                 

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void dfs(int start) {
    push(start);
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (!isEmpty()) {
        int node = pop();
        printf("%d ", node);

        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   
    }

    dfs(0);

    return 0;
}
