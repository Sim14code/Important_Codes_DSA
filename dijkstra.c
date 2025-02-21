#include <stdio.h>
#include <limits.h>
#define V 5

int min_dis(int dis[],int sptSet[]){
    int min=INT_MAX;
    int index;
    for(int i=0;i<V;i++){
        if(!sptSet[i] && min>dis[i]){
            min=dis[i];
            index=i;
        }
    }
    return index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int algo(int graph[][V],int src){
    int dis[V];
    int sptSet[V];

    for(int i=0;i<V;i++){
        dis[i]=INT_MAX;
        sptSet[i]=0;
    }

    dis[src]=0;
    
    for(int i=0;i<V-1;i++){
        int v=min_dis(dis,sptSet);//index of min 
        sptSet[v]=1;
        for(int u=0;u<V;u++){
            if(dis[v]!=INT_MAX && graph[v][u] && !sptSet[u] && graph[v][u]+dis[v]<dis[u]){
               dis[u]= graph[v][u]+dis[v];
            }
        }
    }
    printSolution(dis);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0},
    };

    int src = 0; 
    algo(graph, src);

    return 0;
}
