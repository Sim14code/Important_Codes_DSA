#include <stdio.h>

int bfs(int v,int n,int arr[][n],int visited[n]){
    int rear=-1;
    int front=-1;
    int queue[n];
    queue[++rear]=v;
    printf("%d",v);
     visited[v]=1;
    front++;

    while(front<=rear){
        v=queue[front++];
        for(int i=0;i<n;i++){
            if(arr[v][i]==1 && visited[i]==0){
                    queue[++rear]=i;
                     visited[i]=1;
                     printf("%d",i);

            }
        }

    }
}


int main(){
     int arr[4][4] = {
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 1, 1}
    };
    int visited[4]={0};
    int n=4;

    bfs(0,n,arr,visited);
}