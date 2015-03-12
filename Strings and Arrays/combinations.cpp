/*
STRING COMBINATIONS

Inputs:
input: input string
output: current output
len: length of the input string
depth: depth of the recursion or the index that's being changed
start: the index of the first character in the input string that is still 'available' 
*/

#include <iostream>
#include <cstring>
using namespace std;

void combinations(char *input, char *output, int len, int depth, int start) {
    /* At the current depth, 
	   cycle through the still available letters */

    for( int i = start; i < len; i++ ) {
        output[depth] = input[i];
        combinations(input, output, len, depth+1, i+1);
    }
    output[depth] = '\0';
    cout << output << endl;
}

int main() 
{
    char *input = (char*)"abc";
	char *output = new char[strlen(input) + 1];

	combinations(input, output, strlen(input), 0, 0);
	delete [] output;
    return 0;
}