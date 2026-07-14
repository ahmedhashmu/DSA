#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void searchNode(int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found: " << key << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found\n";
}

void deleteNode(int key) {
    if (head == NULL) return;

    if (head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        cout << "Deleted: " << key << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value not found\n";
    } else {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Deleted: " << key << endl;
    }
}

int main() {
    int choice, value;

    while (1) {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
        } 
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            searchNode(value);
        }
        else if (choice == 4) {
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

