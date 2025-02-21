#include <stdio.h>
#define MAX_NODES 10


void Degree(int mat[][MAX_NODES],int nodes){
    int Incount[MAX_NODES]={0};
    int Outcount[MAX_NODES]={0};
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
        if(mat[i][j]==1){
            Incount[j]++;