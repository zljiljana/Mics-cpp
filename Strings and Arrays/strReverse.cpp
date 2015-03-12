/* Reverse a string */

#include <iostream>
#include <cstring>

using namespace std;

void reverse_string(char s[]) {
	int i=0, j=strlen(s)-1;
	char c;
	while(i < j){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

void normalPrint(char *s)
{
	if(*s) {
		std::cout << *s;
		normalPrint(s+1);
	}
}

void reversePrint(char *s)
{
	if(*s) {
		reversePrint(s+1);
		std::cout << *s;
	}
}


int main() {
	char s[] ="reverse.me";
	reverse_string(s);
	std::cout << s << std::endl;

	string str = "Normal or Reverse";
	normalPrint(&str[0]);
	std::cout << std::endl;
	reversePrint(&str[0]);
	std::cout << std::endl;


	return 0;
}