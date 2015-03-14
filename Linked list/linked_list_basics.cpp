/*
Linked list: the main advantage of lists over arrays is that the lists provide us with the ability to rearrange the items
efficiently. However, this is gained at the expense of quick access ot some random element.

Singly-linked List class bellow has 11 methods:

list( list_node*, list_node* ) - constructor that initializes head and cursor nodes
list( int*, int) - constructor that initializes a linked list from an array
~list() - destructor
prepend( int ) - insert a list element at the beginning of the list
append( int ) - append a list element at the end of the list
print() - print all list elements
printreverse( list_node* ) - print all list elements in reverse
get_head() - return the head element
advance() - move the cursor to the next list element
removeDuplicateNodes() - remove all duplicate elements
deleteNode( list_node* ) - delete the list element

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
	list(const int *arr, int sz);
	~list();
	void prepend( int );
	void append( int );
	void print();
	void printreverse(list_node*);
	list_node* get_head() { return head;}
	void advance() { cursor = cursor->next; };
	void removeDuplicateNodes();
	void deleteNode( list_node* );

private:
	list_node *head;
	list_node *cursor;
};

list::list(const int* arr, int sz){
	head = cursor = 0;
	for(int i=0;i<sz;i++){
		append(arr[i]);
	}
}

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

void list::printreverse(list_node *node){
	if(node == NULL)
		return;

	printreverse(node->next);
	cout << node->data  << "  "; 
}

void list::deleteNode(list_node* d){
	list_node* cur = head;
	list_node* prev = head;
	while(cur) {
		if(cur == d){
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void list::removeDuplicateNodes(){
	// in case we did not populate the list or a list only contains one element
	if(!head || !head->next)
		return;
	cursor = head;
	list_node* iter = head;
	while(cursor){
		iter = cursor->next;
		while(iter){
			if (iter->data == cursor->data){
				deleteNode(iter);
			}
			iter = iter->next;
		}
		advance();
	}
}

int main()
{
	list myList(new list_node(10));
	myList.append(20);
	myList.append(30);
	myList.prepend(10);
	myList.prepend(-1);
	myList.append(-1);
	myList.prepend(-2);
	myList.append(-2);
	myList.append(30);
	myList.append(40);
	
	myList.print();
	cout << "Reverse print: \n";
	myList.printreverse(myList.get_head());
	
	cout << "\nRemove duplicates\n";
	myList.removeDuplicateNodes();
	myList.print();

	cout << "Linked list from an array:\n";
	int arr[] = {1, 2, 3, 4, 5};
  	list myListArr(arr,5);
  	myListArr.append(6);
  	myListArr.prepend(0);
  	myListArr.print();

	return 0;
}