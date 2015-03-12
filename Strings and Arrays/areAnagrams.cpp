/*
A code to dertmine if two strings are anagrams (for example, "listen" and "silent" are anagrams)

This method uses the fact that characters are treated as integers in ASCII table.
So we initialize an array of 256 (zero valued) integers to represent each ASCII character.
Given two strings, one string increases the count of a specific char and the other one decreases it. After that we
simply check if all counts are set to zero, if not, then two strings are not anagrams. 
*/

#include <iostream>
#include <string>

using namespace std;


string areAnagrams(string &s1, string &s2){
	
	int flag[256] = {0};

	if(s1.length() != s2.length())
		return "not anagrams.";

	int i = 0;
	while(s1[i]){
		flag[s1[i++]]++;
	}
	i=0;
	while(s2[i]){
		flag[s2[i++]]--;
	}
	for(i=0;i < 256; i++)
		if(flag[i] > 0)
			return "not anagrams.";

	return "anagrams";
}


int main(){

	string s1 = "listen";
	string s2("silent");
	string s3 = "lathes";

	cout << s1 << " and " << s2 << " are " << areAnagrams(s1,s2) << endl;
	cout << s1 << " and " << s3 << " are " << areAnagrams(s1,s3) << endl;
	cout << s2 << " and " << s3 << " are " << areAnagrams(s2,s3) << endl;

	return 0;
}