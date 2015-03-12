/*
REMOVING SPECIFIED CHARACTERS FROM A STRING

The code below removes specified characters (in this case "aekvoAEVI.") from a string (in this case "I like C++ PROGRAMMING").

We use an array (int flag[256]) to represent ASCII values. Therefore, this method uses additional memory.

*/

#include <iostream>

using namespace std;

void removeChars(char in[], char toremove[]){
	int flag[256] = {0};
	int i=0, last=0;
	while(toremove[i])
		flag[toremove[i++]]++;

	for (i=0;i<strlen(in);i++){
	 	if(flag[in[i]] == 0)
	 		in[last++] = in[i];
	}
	in[last] = '\0';
}

int main()
{
	char input[] = "I like C++ PROGRAMMING.";
	char toremove[] = "aekvoAEVI.";
	cout << "In: " << input << endl;
	cout << "removing " << toremove << "..." << endl;
	removeChars(input,toremove);
	cout << "Out: " << input << endl;

	return 0;
}