#include <stdio.h>

void dfs(int v,int n,int arr[][n],int visited[n]){
    printf("%d ->",v);
    visited[v]=1;
    
    for(int i=0;i<n;i++){
        if(visited [i]==0 && arr[v][i]==1){
            dfs(i,n,arr,visited);
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

    dfs(0,n,arr,visited);
}

