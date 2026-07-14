#include <iostream>
using namespace std;

const int Size = 5;
int hashTable[Size];

void initialize() {
    for (int i = 0; i < Size; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % Size;
}

void insert(int key) {

    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        cout << key << " inserted at index " << index << endl;
    }
    else {
        cerr << "Collision occurred at index " << index << endl;
        cout << "Applying Linear Probing..." << endl;

        int startIndex = index;

        while (hashTable[index] != -1) {
            index = (index + 1) % Size;

            if (index == startIndex) {
                cerr << "Hash Table is FULL! Cannot insert." << endl;
                return;
            }
        }

        hashTable[index] = key;
        cout << key << " inserted at index " << index << endl;
    }
}

void display() {
    cout << endl << "Hash Table:" << endl;
    for (int i = 0; i < Size; i++) {
        cout << i << "  --  ";
        if (hashTable[i] != -1)
            cout << hashTable[i];
        else
            cout << "EMPTY";
        cout << endl;
    }
}

int main() {

    initialize();

    int choice, key;

    while (true) {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Exit";
        cout << endl;
        cout << "\nEnter your choice:  ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key: ";
            cin >> key;
            insert(key);

        } else if (choice == 2) {
            display();

        } else if (choice == 3) {
            cerr << "Exiting the Program" << endl;
            break;

        } else {
            cerr << "Invalid choice! Please choose between 1-3! " << endl;
        }
    }

    return 0;
}
