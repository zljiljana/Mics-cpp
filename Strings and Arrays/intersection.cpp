/* 
INTERSECTION OF TWO CHARACTER STRINGS

This code takes in two character strings and returns a string containing only the characters found in both strings in the order of a.
*/


#include <iostream>

using namespace std;


char* intersection(char a[], char b[]){
	int flag[256] = {};
	int i=0, last=0;
	while(b[i])
		flag[b[i++]]++;

	char *ret = new char[strlen(a)+1];
	for(i=0;i<strlen(a);i++){
		if(flag[a[i]] > 0){
			ret[last++] = a[i];
			flag[a[i]]--;
		}
	}
	ret[last] = '\0';
	return ret;
} 



int main()
{
	char a[] = "stroustrup";
	char b[] = "programmings";
	cout << "a = " << a << "\nb = " << b << endl;
	char *str = intersection(a, b);
	cout << "intersection = " << str << endl;
	delete str;
	return 0;
}