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


Node* sortedMerge(Node *a, Node *b){
	Node *result_node = NULL;

	/* Base cases */
  	if (a == NULL)
    	return(b);
  	else if (b==NULL)
    	return(a);
 
  	/* Pick either a or b, and recur */
  	if (a->data <= b->data){
    	result_node = a;
    	result_node->next = sortedMerge(a->next, b);
    }else {
    	result_node = b;
    	result_node->next = sortedMerge(a, b->next);
  	}
  	//printNodes(result);
	return result_node;
}

void mergeSplit(Node* source, Node** a, Node** b){
	Node* slow;
    Node* fast;
    /* base case, length of the list to split is 0 or 1 */
	if ((source == NULL) || (source->next == NULL)){
    	*a = source;
    	*b = NULL;
    } else {
    	slow = source;
    	fast = source->next;
	    /* 'fast' pointer will advance two nodes, and 'slow' one node at a time */
	    while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL){
				slow = slow->next;
				fast = fast->next;
			}
	    }
	    /* now 'slow' is before the midpoint in the list, so split it in two at that point. */
	    *a = source;
	    *b = slow->next;
	    slow->next = NULL;
	}
}

void mergeSort(Node **headRef){
	Node* h = *headRef;
	Node* a;
	Node* b;
	/* Base case -- head length of 0 or 1 */
	if ((h == NULL) || (h->next == NULL))
    	return;

	/* Split head into 'a' and 'b' sublists */
  	mergeSplit(h, &a, &b);
 
	/* Recursively call mergeSort on two sublists */
  	mergeSort(&a);
  	mergeSort(&b);
 
	/* merge the two sorted lists together */
  	*headRef = sortedMerge(a, b);
}


int main() {
	Node *head = createNode(2);
	insertBack(head, 5);
	insertBack(head, 6);
	insertBack(head, -1);
	insertBack(head, 3);

	cout << "Unsorted list: \t";
	printNodes(head);
	cout << "Sorted list: \t";
	mergeSort(&head);
	printNodes(head);

    return 0;
}
