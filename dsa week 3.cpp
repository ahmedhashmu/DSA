#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = n;
    }

    bool search(int val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == val)
                return true;
            cur = cur->next;
        }
        return false;
    }

    bool deleteValue(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val)
            cur = cur->next;

        if (!cur->next) return false;
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        return true;
    }

    void display() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val;

    while (true) {
        cout << "\n1) Insert\n2) Search\n3) Delete\n4) Display\n5) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin >> val;
            list.insertEnd(val);
        } 
        else if (choice == 2) {
            cin >> val;
            cout << (list.search(val) ? "Found\n" : "Not Found\n");
        } 
        else if (choice == 3) {
            cin >> val;
            cout << (list.deleteValue(val) ? "Deleted\n" : "Not Found\n");
        } 
        else if (choice == 4) {
            list.display();
        } 
        else if (choice == 5) {
            break;
        }
    }
}