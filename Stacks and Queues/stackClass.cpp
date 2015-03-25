/*
Stack class implementation using a linked list. This stack class can return its minimum element. 

All the basic operations like push(), pop(), and peekMin() are O(1) not O(n). 
In order to have constant time peekMin() operation, we need to keep track of the minimum for each stack element. 
To do this, in the code below, each stack gets its own min-value at the time when it was pushed by comparing the minimum of the previous top stack.

We could have a global minimum value, however, there is a problem when the stack with this minimum value is popped. 
Then, we need to update the global min value which may take O(n) operation.

In summary, this code will get the stacks minimum value by peeking the top only, using peekMin() which returns the min-value for the top stack.

*/

#include <iostream>

using namespace std;

#define MIN(a,b) (a<b) ? a : b;

class Stack
{
public:
	Stack(): top(NULL) {} ;
	~Stack();
	void push(int);
	int pop();
	int peek();
	int peekMin();
	friend void print(Stack&);

private:
	typedef struct node {
		node *next;
		int data;
		int min;
	} NODE;

	NODE *top;
};


Stack::~Stack(){
	while(top){
		NODE *tmp = top;
		top = top->next;
		delete tmp;
	}
}

void Stack::push(int n){
	NODE* newN = new NODE;
	newN->data = n;
	newN->next = top;
	if(top == NULL) 
		newN->min = n;
	else
		newN->min = MIN(n, top->min); 
	top = newN;
}

int Stack::pop(){
	NODE *tmp = top;
	int n = tmp->data;
	top = tmp->next;
	cout << "popped: " << n << endl;
	delete tmp;
	return n;
}

int Stack::peekMin(){
	return top->min;
}

int Stack::peek() {
	return top->data;
}

void print(Stack &s){
	Stack::NODE *cur = s.top;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	Stack *st = new Stack;
	st->push(40);
	st->push(50);
	st->push(20);
	st->push(10);
	st->push(30);
	cout << "Print stack: " << endl;
	print(*st);
	cout << "current stack minimum = " << st->peekMin() << endl;
	st->pop();
	cout << "current stack minimum = " << st->peekMin() << endl;
	st->pop();
	cout << "current stack minimum = " << st->peekMin() << endl;
	st->pop();
	cout << "current stack minimum = " << st->peekMin() << endl;
	st->pop();
	cout << "current stack minimum = " << st->peekMin() << endl;
	
	cout << "current top value = " << st->peek() << endl;

	return 0;
}