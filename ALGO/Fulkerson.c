#include <stdio.h>
#include <string.h>
#include <limits.h>

#define V 6

int graph[V][V];
int rGraph[V][V];

int bfs(int s, int t, int parent[]) {
    int visited[V];
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;
    parent[s] = -1;
    
    int queue[V], front = 0, rear = 0;
    queue[rear++] = s;
    
    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 && rGraph[u][v] > 0) {
                queue[rear++] = v;
                visited[v] = 1;
                parent[v] = u;
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}

int fordFulkerson(int s, int t) {
    int parent[V];
    int maxFlow = 0;

    memcpy(rGraph, graph, sizeof(graph));

    while (bfs(s, t, parent)) {
        int pathFlow = INT_MAX;
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < rGraph[u][v]) ? pathFlow : rGraph[u][v];
        }

        maxFlow += pathFlow;
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
    }
    return maxFlow;
}

int main() {
    int graphInput[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    memcpy(graph, graphInput, sizeof(graphInput));
    int source = 0, sink = 5;
    printf("Maximum flow: %d\n", fordFulkerson(source, sink));
    return 0;
}
