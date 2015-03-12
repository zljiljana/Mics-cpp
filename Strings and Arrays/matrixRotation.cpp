/*
A code for rotating a NxN matrix in place

For example, imagine an image that you want to rotate by 90 degrees.

*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int N = 5;

void rotate(int a[][N]){
	
	for (int i = 0;i < N/2;i++){
		for (int j = 0; j < ceil(N/2.0);j++){
			int tmp = a[i][j];
			a[i][j] = a[N-j-1][i];
			a[N-j-1][i] = a[N-i-1][N-j-1];
			a[N-i-1][N-j-1] = a[j][N-i-1];
			a[j][N-i-1] = tmp;
		}
	}
}


int main(){
	
	int a[N][N] = {	{1,2,3,4,5},
		    		{6,7,8,9,10},
		    		{11,12,13,14,15},
		    		{16,17,18,19,20},
		    		{21,22,23,24,25} };

	rotate(a);

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) 
			cout << setw(3) << a[i][j];
		cout << endl;
	}

	return 0;
}