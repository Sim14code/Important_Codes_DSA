#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

void kruskal(Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(edges[0]), compare);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    int cost = 0;
    printf("Edges in MST:\n");
    for (int i = 0, count = 0; count < n - 1 && i < e; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            cost += w;
            unionSet(u, v);
            count++;
        }
    }
    printf("Total cost of MST: %d\n", cost);
}

int main() {
    int n = 4, e = 5;
    Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskal(edges, n, e);
    return 0;
}
