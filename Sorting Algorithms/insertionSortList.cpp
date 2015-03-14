/*
Insertion sort is a very simple sorting algorithm that is relatively efficient for small lists and mostly-sorted lists.
It is often used as part of more sophisticated algorithms. It does sorting by taking elements from the list one by one and 
inserting them in their correct position into a new sorted list. 

The insertion sort works just like its name suggests - it inserts each item into its proper place in the final list.
Pseudo code:
 for i = 1, n
    j = i
    while(j > 0 and E[j] < E[j-1])
        swap(E[j], E[j-1])
        j--

This is an in-place implementation with Linked List from: 
http://analgorithmaday.blogspot.com/2011/01/insertion-sort-with-linked-listin-place.html
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void printList(struct Node *head){
	struct Node* ptr = head;
	while(ptr) {
    	cout << setw(3) << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;
}

struct Node* createNode(int n){
	Node* newN = new struct Node;
	newN->data = n;
	newN->next = NULL;
	return newN;
}

struct Node* append(struct Node** head, int n){
	struct Node* newN = createNode(n);
	struct Node *cur = *head;
	while (cur){
		if(cur->next == NULL){
			cur->next = newN;
			return cur->next;
		}
		cur = cur->next;
	}
	return *head;
}

struct Node* createList(int a[], int sz) {
	struct Node *head = createNode(a[0]);
	for (int i =1;i<sz;i++){
		append(&head, a[i]);
	}
	return head;
}

struct Node* insertionList(struct Node** head){
	if (*head == NULL)
		return *head;

	// unsorted list - we start from the 2nd element
    struct Node *unsorted = (*head)->next;
    while(unsorted != NULL){
        // take key as an element in the unsorted list.
        struct Node *prev = 0;
        struct Node *iter = *head;
        struct Node *key = unsorted;
   
        // iterate within the sorted list and break when node in the sorted part of the list is bigger than the key
        while(iter != NULL){
            if(iter->data < key->data){
                prev = iter;
                iter = iter->next;
            } else
                break;
        }
        // advance the unsorted pointer
        unsorted = unsorted->next;
        // if reached the end of sorted list 
        if(iter == key) 
            continue;
   
        // note down the position to replace in a sorted list
        struct Node *replace = iter;
   
        //move iter to end of the sorted list 
        while(iter->next != key) 
        	iter=iter->next;

		// link to the upsorted list
        iter->next = unsorted;
   
        // delete the key and replace it in sorted list
        if(prev == 0) {
            *head = key;
        } else {
            prev->next = key;
        }
        key->next = replace;
		printList(*head);
    }
    return *head;
}

int main(){
	int arr[] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	int size = sizeof(arr)/sizeof(int);
	struct Node *head = createList(arr, size);
	cout << "Linked-list in-place insertion sort: " << endl;
	printList(head);
	head = insertionList(&head);
	printList(head);

	return 0;
}