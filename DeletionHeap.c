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

int deleteRoot(int arr[],int *n){
     if (*n <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int root=arr[(*n)-1];
    (*n)--;
    heapify(arr,*n,0);
    return root;
}

void print(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}


int main() {
    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original max-heap:\n");
    print(arr, n);

    int deletedValue = deleteRoot(arr, &n);
    printf("Deleted root element: %d\n", deletedValue);

    printf("Heap after deletion:\n");
    print(arr, n);

    return 0;
}

