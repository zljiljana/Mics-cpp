/*
This is a basic queue implementation with a vector as its data structure.

Functions implemented:
push() - push a value to the queue (we can simply use push_back method for this)
pop() - pop the FI value off the queue (FIFO)
print - print a queue
constructor and a destructor
*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct object {
	int data;
} Object;

class Queue {
public:
	explicit Queue(int);
	~Queue();
	void pop();
	void push(int);
	int peek(){return qvec.front()->data;}
	void print();
private:
	vector<Object*> qvec;
};

Queue::Queue(int n){
	Object *ptr = new Object;
	ptr->data = n;
	qvec.push_back(ptr);
}

Queue::~Queue(){
	vector<Object*>::iterator it;
	for(it = qvec.begin(); it != qvec.end(); ++it) {
		delete *it;
	}
	qvec.erase(qvec.begin(), qvec.end());
}

void Queue::push(int n){
    Object *ptr = new Object;
	ptr->data = n;
	qvec.push_back(ptr);
}

void Queue::pop(){
	vector<Object*>::iterator st = qvec.begin();
	cout << "Popped: " << (*st)->data << endl;
	delete *st;
	qvec.erase(st);
}

void Queue::print(){
	for (vector<Object*>::iterator it = qvec.begin();it != qvec.end(); it++){
		cout << (*it)->data << " ";
	}
	cout << endl;
}

int main()
{
	Queue *q = new Queue(10);
	q->push(20);
	q->push(30);
	q->push(40);
	q->push(50);
	q->print();
	q->pop();
	q->pop();
	cout << "First-In value of a queue: " << q->peek() << endl;
	q->print();
	delete q;
	return 0;
}