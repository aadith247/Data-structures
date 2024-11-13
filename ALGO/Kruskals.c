#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int i, int j) {
    if (i != j)
        parent[j] = i;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(edges[0]), compare);
    for (int i = 0; i < n; i++) 
        parent[i] = i;
    
    int count = 0, mstWeight = 0;
    for (int i = 0; i < e; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u != v) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].w);
            mstWeight += edges[i].w;
            Union(u, v);
            count++;
        }
        if (count == n - 1)
            break;
    }
    printf("Weight of MST: %d\n", mstWeight);
}

int main() {
    Edge edges[] = {
        {0, 1, 4}, {0, 7, 8},
        {1, 7, 11}, {1, 2, 8},
        {2, 7, 7}, {2, 3, 7},
        {2, 5, 4}, {3, 5, 14},
        {3, 4, 9}, {4, 5, 10},
        {5, 6, 2}, {6, 7, 1},
        {6, 4, 6}
    };
    kruskal(edges, 7, 13);
    return 0;
}
