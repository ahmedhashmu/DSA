#include <iostream>
using namespace std;
struct Queue {
    int data;
    Queue* next;
};

Queue* front = NULL;
Queue* rear = NULL;

//EnQueue
void EnQueue(int Value) {
    Queue* temp = new Queue;

    temp ->data = Value;
    temp -> next = NULL;

    if (front == NULL) {
        front = temp;
        rear = temp;
    }else
        rear -> next = temp;
        rear = temp;
}

//DeQueue
void Dequeue() {
    if (front == NULL) {
        cout << "Queue is empty! " << endl;
        return;
    }else {
        Queue* temp = front;
        cout<< front -> data << " is the value that is DeQueued! ";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }
}


int main () {
    cout << "Queue is empty press 1 to EnQueue Value" << endl;
    cout << endl;
    cout << "Press 1 for EnQueue" << endl;
    cout << "Press 2 for DeQueue" << endl;
    cout << "Press 3 to Exit" << endl;


    int choice;
    int value;
    cout << endl;


        while (true) {
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice ==1) {
            cout << "Enter a Value you want to EnQueue";
            cin >> value;
            EnQueue(value);
        }

        if (choice ==2) {
            Dequeue();

        }

        if (choice ==3) {
            break;
        }
    }
}

