/*
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list 
to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order. 
The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

The bubble sort algorithm can be easily optimized by observing that the n-th pass finds the n-th largest element 
and puts it into its final place.
*/

#include <iostream>

using namespace std;

void BubbleSort(int a[], int size){
	int i=0,j,k,temp;
	while (i < size-1){
		for(j=0; j < size - 1; j++) {
			if(a[j] > a[j+1]) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
		for(k = 0; k < size; k++) 
		   cout << a[k] <<" ";
	    cout << endl;
	    i++;
	}
}

int main()
{
	int k;
	int a[] = {5,7,1,3,4,9,2,6,8,0};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	for(k = 0; k < sz; k++) 
		cout << a[k] <<" ";
	cout << endl;
	cout << "======================" << endl;
	BubbleSort(a, sz);
	cout << "======================" << endl;
	for(k = 0; k < sz; k++) 
		cout << a[k] <<" ";
	cout << endl;
}