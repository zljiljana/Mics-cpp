/*
Insertion sort is a very simple sorting algorithm that is relatively efficient for small lists and mostly-sorted lists.
It is often used as part of more sophisticated algorithms. It does sorting by taking elements from the list one by one and 
inserting them in their correct position into a new sorted list. 

In arrays, the new list and the remaining elements can share the array's space, but insertion is expensive, requiring shifting all following elements over by one. 
The insertion sort works just like its name suggests - it inserts each item into its proper place in the final list.

Pseudo code:
 for i = 1, n
    j = i
    while(j > 0 and E[j] < E[j-1])
        swap(E[j], E[j-1])
        j--

This is the way we're sorting cards.
Start by picking up a single card to form a hand that is already sorted. For each card picked up, find the right place to 
insert card into the hand, thus maintaining the invariant that the cards in the hand are sorted. When we hold cards in our 
hand, it is easy to insert a card into its correct position because the other cards are just pushed aside a bit to accept 
the new card.
*/
#include <iostream>
#include <iomanip>

using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void insertion(int a[], int sz){
	int j;
	for(int i = 1; i < sz; i++) {
		j = i;
		while(j > 0 && (a[j] < a[j-1])) {
			swap(a[j], a[j-1]);
			j--;
		}
		cout << "\n" << i <<"th pass: ";
		for (int k = 0; k < sz; k++) 
			cout << setw(3) << a[k];
	}
}

int main()
{
	int a[] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	int size = sizeof(a)/sizeof(int);
	cout << "Unsorted list:  ";
	for (int i = 0; i < size; i++) 
		cout << setw(3) << a[i];
	insertion(a, size);
	cout << endl;

	return 0;
}