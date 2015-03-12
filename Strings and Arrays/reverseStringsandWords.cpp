/*
REVERSE THE STRING AND WORDS.

The following code reverses words using spaces as delimiters. 
First, it reverses all characters. For example, convert "Ludwig Van Beethoven" to "nevohteeB naV giwduL". Then, we reverse each word one by one.

In: Ludwig Van Beethoven
Out: Beethoven Van Ludwig

*/

#include <iostream>

using namespace std;

void reverse(char s[], int start, int end){
	char tmp;
	for(int i=start, j=end; i<j; i++, j--){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void reverseWords(char in[]){
	if (strlen(in) < 2)
		return;

	reverse(in, 0, strlen(in)-1);
	cout << in << endl;

	int i=0, j=0;
	while(in[i]){
	 	if(in[i] == ' '){
	 		reverse(in, j, i-1);
	 		j = i+1;
		}
		i++;
	}
	reverse(in, j, i-1);
}

int main()
{
	char myStr[] = "Ludwig Van Beethoven";

	cout << "In: " << myStr << endl;
	reverseWords(myStr);
	cout << "Out: " << myStr << endl;

	return 0;
}