#include <iostream>
using namespace std;

const int SIZE = 10;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class HashTable {
private:
    Node* table[SIZE];

public:
    HashTable() {
        for(int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        Node* newNode = new Node(key);

        if(table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        for(int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable h;

    h.insert(75);
    h.insert(88);
    h.insert(23);
    h.insert(125);
    h.insert(85);

    h.display();
}
