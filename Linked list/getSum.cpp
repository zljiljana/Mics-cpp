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
sumList(list_node* , list_node* ) - create a list formed from the digits of a sum of two given lists

getNumber() - return an integer from list elements (we assume each node stores single digit number)

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
	void sumList(list_node* , list_node* );

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

int getNumber(list_node* head){
	list_node* cur = head;
	int digit = 0;
	while (cur){
		digit *=10;
		digit += cur->data;
		cur = cur->next;
	}
	return digit;
}

void list::sumList(list_node* head1, list_node* head2){
	int sum = getNumber(head1)+getNumber(head2);
	while (sum){
		prepend(sum % 10);
		sum /= 10;
	}
}

int main()
{
	list myList1(new list_node(5));
	myList1.append(2);
	myList1.append(3);
	cout << "List 1: ";
	myList1.print();

	int arr[] = {5, 1, 9};
  	list myList2(arr,3);
  	myList2.prepend(0);
  	cout << "List 2: ";
  	myList2.print();
 
  	list mySumList;
  	mySumList.sumList(myList1.get_head(), myList2.get_head());
  	cout << "List representing their sum: ";
  	mySumList.print();

	return 0;
}