/*

ROTATING STRINGS

Given two strings, s1 and s2, this code is checking if s2 is a rotation of s1.
The code creates a new string which holds s1+s1, and then it uses a call to a routine 
which checks if one word is a substring of another. 

*/
#include <iostream>

using namespace std;

bool rotationStrings(char s1[], char s2[]){
	bool res = false;
	if(s1 == NULL || s2 == NULL)
		return false;
	if(strlen(s1) != strlen(s2))
		return false;

	char *s3 = new char[strlen(s1)*2+1];
	strcpy(s3,s1); // copy s1 into s3
	strcat(s3,s1); // concatenate s1 into s3

	if(strstr(s3,s2))
		res = true;
	delete [] s3;
	return res;
}


int main() {
	char *s1 = (char*)"apple";
	char *s2 = (char*)"leapp";  /* rotation */
	char *s3 = (char*)"laepp";  /* not a rotation */
	char *s4 = (char*)"pplea";  /* rotation */

	if(rotationStrings(s1,s2))  
		cout << s2 << " is a rotation of " << s1 << endl;
	else
		cout << s2 << " is not a rotation of " << s2 << endl;

	if(rotationStrings(s1,s3))  
		cout << s3 << " is a rotation of " << s1 << endl;
	else
		cout << s3 << " is not a rotation of " << s1 << endl;

	if(rotationStrings(s1,s4))  
		cout << s4 << " is a rotation of " << s1 << endl;
	else
		cout << s4 << " is a rotation of " << s1 << endl;

	return 0;
}