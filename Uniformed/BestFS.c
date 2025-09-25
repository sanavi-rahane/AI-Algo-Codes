#include <stdio.h>

#define MAX 20

int g[MAX][MAX];    
int h[MAX];         
int seen[MAX];     
int n;              


int qNode[MAX], qH[MAX];  //open list qNode and heuristic value array qh
int qSize = 0;


void add(int node, int val) {  //0 40,1 32
    qNode[qSize] = node;
    qH[qSize] = val;
    qSize++; //1,2,3,4,5

    
    for (int i = 0; i < qSize - 1; i++) {  //0 0<1
        for (int j = i + 1; j < qSize; j++) {  //1  1<2
            if (qH[i] > qH[j]) {
                int t1 = qH[i];
                qH[i] = qH[j]; 
                qH[j] = t1;
                int t2 = qNode[i]; 
                qNode[i] = qNode[j]; 
                qNode[j] = t2;
            }
        }
    }
}

// remove first (smallest h)
int take() {
    int node = qNode[0];
    for (int i = 1; i < qSize; i++) {
        qNode[i - 1] = qNode[i];
        qH[i - 1] = qH[i];
    }
    qSize--;//-1
    return node;
}

int empty() {
    return qSize == 0;
}


void bfs(int start, int goal) {  //0 7
    add(start, h[start]);   //0 40
    seen[start] = 1;

    while (!empty()) {
        int node = take(); //0
        printf("%d ", node);

        if (node == goal) {
            printf("\nReached goal %d!\n", goal);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (g[node][i]==1 && seen[i]==0) {
                add(i, h[i]);  //4 19   5 17
                seen[i] = 1;
            }
        }
    }
    printf("\nGoal not reachable!\n");
}

int main() {
    int edges, u, v, s, goal;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        seen[i] = 0;
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++) {
        printf("h(%d): ", i);
        scanf("%d", &h[i]);
    }

    printf("Enter start and goal node: ");
    scanf("%d %d", &s, &goal);

    printf("Best First Search Path: ");
    bfs(s, goal); //0 7

    return 0;
}
