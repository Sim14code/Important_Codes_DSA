#include <stdio.h>
#include <stdlib.h>

struct List {
    int dest;
    struct List* next;
};

struct graph {
    int numNodes;
    struct List** array;
};

struct List* CreateList(int dest) {
    struct List* newNode = (struct List*)malloc(sizeof(struct List));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct graph* CreateGraph(int num) {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->numNodes = num;

    graph->array = (struct List**)malloc(num * sizeof(struct List*));
    for (int i = 0; i < num; i++) {
        graph->array[i] = NULL;
    }
    return graph;
}

void addEdge(struct graph* graph, int src, int dest) {
    struct List* newNode = CreateList(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = CreateList(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

void printGraph(struct graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        struct List* temp = graph->array[i];
        printf("Node %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int numNodes = 5;
    struct graph* graph = CreateGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
