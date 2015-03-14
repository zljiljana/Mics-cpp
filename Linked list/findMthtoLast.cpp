/*
Find m_th to last element in a linked list
*/

#include <iostream>
using namespace std;


typedef struct node{
	int data;
	node* next;
} Node;

Node* createNode(int data){
	Node *newN = new Node();
	newN->data = data;
	newN->next = NULL;
	return newN;
}

void printNodes(Node* head){
	if (head !=NULL){
		Node *cur = head;
		while(cur){
			cout << cur->data << "\t";
			cur = cur->next;
		}
		cout << endl;
	}
	else {
		cout << "\nThe list is empty." << endl;
	}
}

void insertBack(Node *head, int dat){
	Node* cur = head;
	while(cur){
		if(cur->next == NULL){
			cur->next = createNode(dat);
			break;
		}
		cur = cur->next;
	}
}

Node* insertFront(Node** head, int dat){
	Node *newN = createNode(dat);
	if(*head != NULL){
		newN->next = *head;
	}
	*head = newN;
	return *head;
}

Node* deleteNode(Node** head){
	Node* tmp = *head;
	if(*head){
		*head = tmp->next;
		delete tmp;
	}
	return *head;
}


Node *findMthToLast(Node *head, int mth) {
	Node *cursor = head;
	Node *mthBehind = head;

	// advance cursor to the mth position
	for(int i = 0; i < mth; i++) {
		if(cursor)
			cursor = cursor->next; 
		else
			return NULL;
	}
	// advance cursor and mthBehind together, once the cursor hits the end we have our mthBehind
	while(cursor) {		
		cursor = cursor->next;
		if(cursor) 
			mthBehind = mthBehind->next;
	}
	return mthBehind;
}

int main() {
	Node *head = createNode(2);
	insertBack(head, 5);
	insertBack(head, 6);
	insertBack(head, -1);
	insertBack(head, 3);
	printNodes(head);

	for (int i = 0; i < 5; i++) {
		Node *found = findMthToLast(head, i);
		if(found)
			cout << i << "-th to last = " << findMthToLast(head, i)->data << endl;
	}

    return 0;
}