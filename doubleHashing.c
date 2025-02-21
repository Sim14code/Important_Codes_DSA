#include <stdio.h>
#define SIZE 10
int HashTable[SIZE];


void Initialise(){
    for(int i=0;i<SIZE;i++){
        HashTable[i]=-1;
    }    
}

int PrimeFunction(int key){
    return key%SIZE;
}

int SecFunction(int key){
    return 7-(key%7);
}

void Insert(int key){
    int index=PrimeFunction(key);
    int sideVal=SecFunction(key);
    int i=0;

    while(HashTable[index] != -1){
        index=(index+i* sideVal)%SIZE;
        i++;

        if(i==SIZE){
            printf("Cannot be added Table is full");
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
    int index=PrimeFunction(key);
    int sideVal=SecFunction(key);
    int i=0;

    while(HashTable[index] != -1){
        if(HashTable[index]==key){
            return index;
        }
        index=(index+sideVal)%SIZE;
        i++;
        if(i==SIZE){
            printf("");
            break;
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
    int stuff=Search(37);
    printf("%d",stuff);
}
