#include <stdio.h>
#define SIZE 10
int HashTable[SIZE];


void Initialise(){
    for(int i=0;i<SIZE;i++){
        HashTable[i]=-1;
    }    
}

int HashFunction(int key){
    return key%SIZE;
}

void Insert(int key){
    int index=HashFunction(key);

    while(HashTable[index] != -1){
        index=(index+1)%SIZE;
    }

    HashTable[index]=key;
}

void Display(){
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (HashTable[i] != -1) {
            printf("Index %d: %d\n", i, HashTable[i]);
        } else {
            printf("Index %d: ~\n", i);
        }
    }

}


int Search(int key){
    int index=HashFunction(key);
    while(HashTable[index] != -1){
        if(HashTable[index]==key){
            printf("found at %d",index);
            return 1;
        }
        else{
            index=(index+1)%SIZE;
        }
    }
    return -1;
}

int main(){
    Initialise();

    int keys[] = {23, 43, 13, 27, 78, 37, 24, 30};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        Insert(keys[i]);
    }

    Display();
}
