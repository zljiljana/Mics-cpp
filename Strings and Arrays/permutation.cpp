/*
STRING PERMUTATION 

Implement a routine that prints all possible ordering of the characters in a string. Treat each character in the 
input string as a distinct characters, even if it is repeated. In other words, given the string "aaa", the routine
 should print "aaa" six times.

The solution implemented here is using backtracking 
checkout: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/ for further reference

*/

#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
    char temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void permuteA(char *a, int st, int end)
{
    if(st == end)
		cout << a << endl;
    else {
		for(int i = st; i <= end; i++) {
			swap(a+st, a+i);
			permuteA(a, st+1, end);
			swap(a+st, a+i);
	    }
    }
}


int main() {
    char s[] = "ABC"; 
    permuteA(s, 0, strlen(s)-1);

    return 0;
}