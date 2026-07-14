  #include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

const int SIZE = 10;

Node* HT[SIZE];

int hashfunction(int value) {
	return value % SIZE ;
}

void insert(int value){
	int ind = hashfunction(value);

	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;

	 b  
	if (HT[ind] == NULL) {
		HT[ind] = temp;
	}
	else {
		
	Node* curr = HT[ind];
	while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void display(){
	for (int i = 0; i < SIZE; i++ ){
	cout << i << " -> ";
	Node* curr = HT[i];

		while (curr != NULL){
		cout << curr->data << " -> ";
		curr = curr->next;
		}
		cout << "NULL" << endl;
	}
}

int main(){

	for (int i = 0; i < SIZE; i++ ){
		HT[i] = NULL;
	}

	insert(15);
	insert(45);
	insert(25);
	insert(6);
	insert(9);
	insert(11);

	display();

	return 0;
}