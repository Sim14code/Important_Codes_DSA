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
    int i=1;
    while(HashTable[index] != -1){
        index=(index+i*i)%SIZE;
        i++;

        if(i==SIZE){
        printf("Table is full! Cannot insert key %d\n", key);
        return;
        }
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
    int i=1;   
    while(HashTable[index] != -1){
        if(HashTable[index]==key){
            printf("found at %d",index);
            return 1;
        }
        else{
            
            index=(index+i*i)%SIZE;
            i++;
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
