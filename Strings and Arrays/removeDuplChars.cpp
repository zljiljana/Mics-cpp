/* 
REMOVE DUPLICATE CHARACTERS IN A STRING

Method A: A code to remove duplicate characters in a string without using any additional buffer (no extra copy 
of the array).

Method B: A code to remove duplicate characters in a strings with auxiliary memory (array of integers representing
ASCII counts)

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void removeDuplicateA(string &s){
	if(s.length() < 2)
		return;
	int i = 1, j;
	int last = 1;
	int lng = s.length();
	while (i < lng){
		for (j = 0;j < last;j++){
			if(s[i] == s[j])
				break;
		}
	 	if (j == last){
	 		s[last++] = s[i];
		}
	 	i++;
	}
	s.resize(last);
}

void removeDuplicateB(string &s){
	if(s.length() < 2)
		return;
	int flag[256] = {0};
	int lng = s.length();
	int i=0, last=0;
	while (i < lng){
		flag[s[i]]++;
		if(flag[s[i]] == 1){
			s[last++] = s[i];
		}
		i++;
	}
	s.resize(last);
}

int main() {
	const int M = 6;
	string s[M] = {"aaaa", "abc", "ababaav", "fsvereaa", "ljiljana", ""};
	for(int i = 0; i < M; i++) {
		cout << s[i];
		//removeDuplicateA(s[i]);
		removeDuplicateB(s[i]);
		cout << " ----> " << setw(6) << s[i] << endl;
	}
	return 0;
}