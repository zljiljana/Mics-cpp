/*
This is a basic stack implementation with a linked list as its data structure.

Functions implemented:
push() - push a value to the stack (we must keep track of a top element)
pop() - pop the top of the stack
printStack - print
deleteStack - delete a stack
*/

#include <iostream>

using namespace std;

struct treeNode{
	int data;
	treeNode* next;
};

void createStack(treeNode** top){
	*top = NULL;
}

void push(treeNode** top, int* n){
	treeNode* newNode = new treeNode;
	newNode->data = *n;
	newNode->next = *top;
	*top = newNode;
}

void pop(treeNode** top, int& n){
	if(*top == NULL)
		return;
	treeNode* tmp = *top;
	n = tmp->data;
	*top = tmp->next;
	delete tmp;
}

void printStack(treeNode *head){
	if (head==NULL){
		cout << "Stack is empty.\n";
		return;
	}
	treeNode* cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

void deleteStack(treeNode** top){
	treeNode* tmp;
	while(*top){
		tmp = (*top)->next;
		delete *top;
		*top = tmp;
	}
}

int main()
{
	treeNode *head;
	int n;
	createStack(&head);
	int n1 = 10, n2 = 20, n3 = 30, n4 = 40, n5 = 50;
	push(&head, &n1);
	push(&head, &n2);
	push(&head, &n3);
	push(&head, &n4);
	push(&head, &n5);
	cout << "Values in a stack: ";
	printStack(head);

	pop(&head, n);
	cout << "popped " << n << endl;
	pop(&head, n);
	cout << "popped " << n << endl;
	cout << "Values in a stack: ";
	printStack(head);

	cout << "deleting a stack..." << endl;
	deleteStack(&head);
	printStack(head);

	return 0;
}