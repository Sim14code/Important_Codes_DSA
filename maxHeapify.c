#include <stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n, int i){
    int parent=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[i]<arr[left]){
        parent=left;
    }
     if(right<n && arr[i]<arr[right]){
        parent=right;
    }
    if(parent!=i){
        swap(&arr[parent],&arr[i]);
        heapify(arr,n,parent);
    }
}

void build(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void print(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

int main() {
    int arr[] = {9, 6, 5, 0, 8, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    build(arr, n);

    printf("Max-Heap array: ");
    print(arr, n);

    return 0;
}