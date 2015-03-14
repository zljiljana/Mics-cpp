/*
Linked list: the main advantage of lists over arrays is that the lists provide us with the ability to rearrange the items
efficiently. However, this is gained at the expense of quick access ot some random element.

Singly-linked List class bellow has 10 methods:

list( list_node*, list_node* ) - constructor that initializes head and cursor nodes
~list() - destructor
prepend( int ) - insert a list element at the beginning of the list
append( int ) - append a list element at the end of the list
print() - print all list elements
get_head() - return the head element
advance() - move the cursor to the next list element
makeCircular( int ) - make a list circular at the node with the given value
circularAt() - find where the list is circular
breakTheCircle() - break the circle

The list class two private members:

head - pointer to the first element of the list
cursor - pointer to the current element of the list, having this element just simplifies some functions

*/


#include <iostream>
using namespace std;

typedef struct list_node {
	list_node(int n = 0, list_node* nextPtr = NULL): data(n), next(nextPtr) {};

	int data;
	list_node* next;
}list_node;

class list{
public:
	list(list_node *h = NULL, list_node *c = NULL): head(h), cursor(c) {};
	~list();
	void prepend( int );
	void append( int );
	void print();
	list_node* get_head() { return head;}
	void advance() { cursor = cursor->next; };
	void makeCircular( int );
	int circularAt();
	void breakTheCircle();

private:
	list_node *head;
	list_node *cursor;
};


list::~list(){
	cursor = head;
	while (cursor){
		head = cursor->next;
		delete cursor;
		cursor = head;
	}
}

void list::append( int n){
	if(head){
		cursor = head;
		while(cursor){
			if(cursor->next == NULL){
				cursor->next = new list_node(n);
				break;
			}
			advance();
		}
	} else
		head = new list_node(n);
}

void list::prepend( int n){
	if (!head){
		head = new list_node(n, head);
	} else{
		cursor = new list_node(n, head);
		head = cursor;
	}
}

void list::print(){
	if (head){
		cursor = head;
		while(cursor){
			cout << cursor->data << "  ";
			advance();
		}
		cout << endl;
	} else
		cout << "The list is empty." << endl;
}

void list::makeCircular( int n){
	cursor = head;
	list_node* tmp;
	while(cursor){
	 	if (cursor->data == n){
	 		tmp = cursor;
	 	}
	 	if(cursor->next == NULL){
	 		break;
	 	}
	 	advance();
	}
	cursor->next = tmp;
	return;
}

int list::circularAt(){
	cursor = head;
	list_node* fast_cursor = head;
	// one iterator will go one node at a time, the other will go two nodes at a time
	while(cursor){
		advance();
		if (fast_cursor->next == NULL) return 0;
		fast_cursor = fast_cursor->next;
		if (fast_cursor->next == NULL) return 0;
		fast_cursor = fast_cursor->next;
		if(cursor == fast_cursor)
			break;
	}
	cursor = head;
	while(cursor){
		advance();
		fast_cursor = fast_cursor->next;
		if (cursor == fast_cursor){
			return cursor->data;
		}
	}
	return 0;
}

void list::breakTheCircle(){
	cursor = head;
	list_node* fast_cursor = head;
	list_node* prev = head;
	// one iterator will go one node at a time, the other will go two nodes at a time
	while(cursor){
		advance();
		if (fast_cursor->next == NULL) return;
		fast_cursor = fast_cursor->next;
		if (fast_cursor->next == NULL) return;
		fast_cursor = fast_cursor->next;
		if(cursor == fast_cursor)
			break;
	}
	cursor = head;
	while(cursor){
		prev = fast_cursor;
		advance();
		fast_cursor = fast_cursor->next;
		if (cursor == fast_cursor){
			prev->next = NULL; 
			return ;
		}
	}
	return;
}

int main()
{
	list myList(new list_node(1));
	myList.append(2);
	myList.append(3);
	myList.prepend(-1);
	myList.prepend(-2);
	myList.append(4);
	myList.append(5);
	myList.append(6);
	myList.append(7);
	
	myList.print();
	/* First we need to make a list circular at node with some value */
	cout << "Making a list circular at 4 ...";
	myList.makeCircular(4);
	cout << "\nList is circular at " << myList.circularAt() << endl;
	myList.breakTheCircle();
	myList.print();

	return 0;
}