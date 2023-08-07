#include <stdio.h>
#include <stdbool.h>
#define TABLE_SIZE 10
struct KeyValue {
    int key;
    int value;
};
struct KeyValue hashTable[TABLE_SIZE];
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;

        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index].key != key) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex || hashTable[index].key == -1) {
            printf("Key %d not found.\n", key);
            return -1;
        }
    }
    return hashTable[index].value;
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key=%d, Value=%d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
    }
    insert(5, 50);
    insert(12, 120);
    insert(3, 30);
    insert(22, 220);
    insert(7, 70);

    display();

    int keyToSearch = 12;
    int value = search(keyToSearch);
    if (value != -1) {
        printf("Value for key %d: %d\n", keyToSearch, value);
    }

    return 0;
}

