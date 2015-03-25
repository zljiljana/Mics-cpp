/*
This is a basic queue implementation with a linked list as its data structure.

Functions implemented:
push() - push a value to the queue (we keep track of a first-in element and we loop through entire queue to add an element in the end)
pop() - pop the top off the queue (FIFO)
display - print a queue

*/

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct node {
	int data;
	node *next;
} Node;

void createQueue(Node **head){
	*head = NULL;
}

void push(Node** head, int n){
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	if(*head == NULL) {
		*head = newNode;
		return;
	}

	Node *cur = *head;
	while(cur) {
		if(cur->next==NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void pop(Node** head)
{
	if(*head==NULL) 
		return;
	Node *tmp = *head;
	*head = (*head)->next;
	delete tmp;
}

void display(Node* head)
{
	Node *cur = head;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	Node *head;
	createQueue(&head);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	display(head);
	pop(&head);
	display(head);
	pop(&head);
	display(head);
	pop(&head);
	display(head);
	pop(&head);
	display(head);

	return 0;
}