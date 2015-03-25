/*
Queue class implementation using a linked list.

All the basic methods were impplemented:
push a value
pop a value
print the queue

*/

#include <iostream>
#include <iomanip>

using namespace std;

class Queue {
public:
	Queue();
	~Queue();
	void push(int);
	int pop();
	void print();
private:
	typedef struct Node {
		Node *next;
		int data;
	} NODE;
	NODE* head;
};

Queue::Queue(){
	head = NULL;
}

Queue::~Queue(){
	while(head){
		NODE *tmp = head;
		head = head->next;
		delete tmp;
	}
}

void Queue::push(int n){
	NODE* newN = new NODE;
	newN->data = n;
	newN->next = NULL;
	if(head==NULL){
		head = newN;
		return;
	}
	NODE *tmp = head;
	while(tmp){
		if(tmp->next == NULL){
			tmp->next = newN;
			return;
		}
		tmp = tmp->next;
	}
}

int Queue::pop(){
	if (head == NULL){
		cout << "The queue is empty.";
		return 0;
	}
	NODE* tmp = head;
	int ret = head->data;
	head = head->next;
	delete tmp;
	cout << "Popped: " << ret << endl;
	return ret;
}

void Queue::print(){
	NODE *cur = head;
	while(cur){
		cout << cur->data << "  ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	Queue *que = new Queue();
	que->push(10);
	que->push(20);
	que->push(30);
	que->push(40);
	que->push(50);
	que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();
	que->pop();que->print();

	return 0;
}