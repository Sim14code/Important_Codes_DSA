#include <stdio.h>
#define MAX 100

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insert(int heap[],int *n,int key){
    heap[*n]=key;
    int i=*n;
    (*n)++;

    while(i!=0 && heap[i]<heap[(i-1)/2]){
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }

}

void print(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}
int main() {
    int heap[MAX];
    int n = 0;
    int elements[] = {9, 6, 5, 0, 8, 2, 1, 3};
    int size = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < size; i++) {
        insert(heap, &n, elements[i]);
    }
    printf("Min-Heap array: ");
    print(heap, n);
    return 0;
}
