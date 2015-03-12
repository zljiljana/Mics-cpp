/*
Replacing spaces in a string with special characters.

In this example we will replace the spaces with "#456".

*/

#include <iostream>
#include <string>

using namespace std;

void replaceSpaces(string& s){
	string specString = "#456";
	int i=0, j=0, cnt = 0;
	// count the number of spaces in s
	while(s[i])
		if(s[i++]== ' ')
			cnt++;
	
	if(cnt==0)
		return;
	// create a new string to hold the new version of an old string with replaced spaces
	char* newS = new char[s.length() + cnt*specString.length() + 1];

	for(i=0; i<s.length(); i++){
		if (s[i] == ' '){
			newS[j++] = specString[0];
			newS[j++] = specString[1];
			newS[j++] = specString[2];
			newS[j++] = specString[3]; 
		}
		else{
			newS[j] = s[i]; 
			j++;
		}
	}
	newS[j] = '\n';
	cout << newS;
}

int main() {
	string s = "Replace spaces with special characters. ";
	cout << "The original string: " << s << endl;
	replaceSpaces(s);

	return 0;
}