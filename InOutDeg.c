#include <stdio.h>
#define MAX_NODES 10


void Degree(int mat[][MAX_NODES],int nodes){
    int Incount[MAX_NODES]={0};
    int Outcount[MAX_NODES]={0};
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
        if(mat[i][j]==1){
            Incount[j]++;
            Outcount[i]++;
        }
        }

         printf("Node\tIn-Degree\tOut-Degree\n");
        for (int i = 0; i <nodes; i++) {
        printf("%d\t%d\t\t%d\n", i, Incount[i], Outcount[i]);
         }
      
    }
}

int main(){

        int nodes;
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    Degree(graph, nodes);



    return 0;

}