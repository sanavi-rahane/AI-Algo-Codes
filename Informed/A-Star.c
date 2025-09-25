#include <stdio.h>
#include <stdbool.h>

#define MAX 20
#define INF 9999

int graph[MAX][MAX];   // adjacency matrix
int h[MAX];            // heuristic values
int n;                 // number of vertices

int visited[MAX];      // visited nodes
int parent[MAX];       // to store path

// Function to find node with minimum f = g+h
int getMinNode(int open[], int g[]) {
    int min = INF, minNode = -1;
    for (int i = 0; i < n; i++) {
        if (open[i] && !visited[i] && g[i] + h[i] < min) {
            min = g[i] + h[i];
            minNode = i;
        }
    }
    return minNode;
}

void Astar(int start, int goal) {
    int g[MAX];     // cost from start
    int open[MAX];  // open list

    for (int i = 0; i < n; i++) {
        g[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
        open[i] = 1;
    }

    g[start] = 0;

    while (1) {
        int node = getMinNode(open, g);
        if (node == -1) break;   // no path

        visited[node] = 1;
        printf("%d ", node);

        if (node == goal) {
            printf("\nReached goal %d!\n", goal);

            // Print path
            printf("Path: ");
            int path[MAX], idx = 0;
            while (node != -1) {
                path[idx++] = node;
                node = parent[node];
            }
            for (int i = idx - 1; i >= 0; i--)
                printf("%d ", path[i]);
            printf("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                int new_g = g[node] + graph[node][i];
                if (new_g < g[i]) {
                    g[i] = new_g;
                    parent[i] = node;
                }
            }
        }
    }

    printf("\nGoal not reachable!\n");
}

int main() {
    int edges, u, v, w, start, goal;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++) {
        printf("h(%d): ", i);
        scanf("%d", &h[i]);
    }

    printf("Enter start and goal node: ");
    scanf("%d %d", &start, &goal);

    printf("A* Search Order: ");
    Astar(start, goal);

    return 0;
}
