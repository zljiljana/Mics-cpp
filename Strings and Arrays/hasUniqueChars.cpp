/*
A code to check if a string has all unique chararacters. 

This method uses the fact that ASCII characters are treated as integers. 
First we create an array of 256 zero-initialized integers. Then, we index this array using chars from the 
string and increment its value. The value represents the count for a given char. If the count is greater 
than 1 we know there are repeating characters.

*/

#include <iostream>
#include <string>

using namespace std;

bool hasUniqueChars(string &s){
	if (s.length() <= 1)
		return false;

	int flag[256] = {0}; // 256 for extended ASCII character set

	for(int i=0; i<s.length(); i++){
		flag[s[i]]++;
		if(flag[s[i]] > 1)
			return false;
	}
	return true;
}

int main(){

	string s1 = "aaa";
	cout << "Is " << s1 << " unique? \n" << hasUniqueChars(s1) << endl;

	return 0;
}