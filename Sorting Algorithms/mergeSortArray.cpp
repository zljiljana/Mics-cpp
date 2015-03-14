/*
Merge sort

time: O(nlogn) – worst/best/average
memory: worst case O(n) auxiliary (when working on arrays); O(1) when working on linked lists.

Merge sort is divide and conquer algorithm, it is stable (two same elements will not be swapped) and parallelizable.
Merge sort can be easily adapted to operate on linked lists and very large lists that reside in slow-to-access media.

Basic idea:
1. Divide the unsorted list into n sublists, each containing 1 element
2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining.
So, merge sequence to be sorted: s_i, ..., s_j 
will be divided into two nearly equal sequences: s_i, ..., s_m        s_m+1, ..., s_j  
where m = floor((i+j)/2). Each of these two sequences are recursively sorted after which they are combined to produce the sorted arrangement of the original sequence

*/

#include <iostream>
using namespace std;

void print(int a[], int sz){
	for (int i = 0; i < sz; i++) cout << a[i] << " ";
	cout << endl;
}
 
void mergeA(int a[], const int low, const int mid, const int high) {
	int *temp = new int[high-low+1];
        
	int left = low;
	int right = mid+1;
	int current = 0;

	// Merges the two arrays into temp[] 
	while(left <= mid && right <= high) {
		if(a[left] <= a[right])
			temp[current++] = a[left++];
		else // if right element is smaller that the left
			temp[current++] = a[right++];  
	}

	// Completes the array, copy the remainder of the left and right part of the sequence
	while (left <= mid)
		temp[current++] = a[left++];
	while (right <= high)
		temp[current++] = a[right++];

	// copies the temp into the original array
	for(int i=0; i<=high-low;i++) 
                a[i+low] = temp[i];

	delete[] temp;
}
 
void merge_sortA(int a[], const int low, const int high)
{
	if(low >= high) return;
	int mid = (low+high)/2;
	merge_sortA(a, low, mid);  //left half
	merge_sortA(a, mid+1, high);  //right half
	mergeA(a, low, mid, high);  //merge them
}
 

// a: original, b: helper array
void mergeB(int a[], int b[],  int low, int mid, int high)
{
	for(int i = low; i <= high; i++)
		b[i] = a[i];

	int left = low;
	int right = mid+1;
	int index = low;
	while(left <= mid && right <= high) {
		if(b[left] <= b[right]) 
			a[index++] = b[left++];
		else 
			a[index++] = b[right++];
	}

	// copy remainder of the left side
	int remainder = mid - left +1;
	for(int i = 0; i < remainder; i++) {
		a[index+i] = b[left+i];
	}
}

// merge sort starts here
void mergeSortB(int a[], int b[], int low, int high)
{
	if(low >= high) return;
	int mid = (low+high)/2;
	mergeSortB(a, b, low, mid);
	mergeSortB(a, b, mid+1, high);
	mergeB(a, b, low, mid, high);
}

// prepare for real mergesortB()
void merge_sortB(int a[], int len)
{
	int *b = new int[len];
	mergeSortB(a, b, 0, len-1);
	delete[] b;
}

int main()
{        
	int a[] = {15,  9,  8,  1,  4, 11,  7, 12, 13,  6,  5,  3, 16,  2, 10, 14};
	int size_a = sizeof(a)/sizeof(int);
	int b[] = {15,  9,  8,  1,  4, 11,  7, 12, 13,  6,  5,  3, 16,  2, 10, 14};
	int size_b = sizeof(b)/sizeof(int);

	cout << "Merge sort " << endl;
	print(a, size_a);
	merge_sortA(a, 0, size_a-1 );   
	print(a, size_a);

	cout << "Merge sort with auxiliary vector b: " << endl;
	merge_sortB(b, size_b);
	print(b, size_b);

	return 0;
}