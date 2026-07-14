#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Forward display using recursion
void displayForward(Node* head) {
    if(head == NULL)
        return;

    cout << head->data << " ";
    displayForward(head->next);
}

// Reverse display using recursion
void displayReverse(Node* head) {
    if(head == NULL)
        return;

    displayReverse(head->next);
    cout << head->data << " ";
}

int main() {
    // Create nodes manually
    Node* head = new Node;
    head->data = 10;
    head->next = new Node;

    head->next->data = 20;
    head->next->next = new Node;

    head->next->next->data = 30;
    head->next->next->next = new Node;

    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    cout << "Forward: ";
    displayForward(head);

    cout << "\nReverse: ";
    displayReverse(head);

    return 0;
}
