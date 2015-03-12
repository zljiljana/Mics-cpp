/*
BASE CONVERSION

Given a series A,B,C .......Z, AA, AB,AC,AD....AZ,BA,BB...BZ,CA....(Open excel sheet. The names of column represent the series). Given input as number 'n'. Output the 'n'th string of the series. Also, vice versa if given a string print its corresponding number.

E.g given AC then its integer is 29, given 702 its string value is ZZ...

*/

#include <iostream>

using namespace std;


int columnNumber(string &s) {
	int res = 0, i=0;
	while(s[i]){
		res = 26*res + (s[i] - 'A' + 1);
		i++;
	}
	return res;
}

void reverse(char l[], int end){
	char tmp;
	for(int i=0,  j = end-1; i < j ;i++, j--){
		tmp = l[i];
		l[i] = l[j];
		l[j] = tmp;
	}
	l[end] = '\0';
}

void columnLabel(int n, char label[]){
	int i=0;
	while(n>0){
		label[i++] = ((n-1)%26) + 'A';
		n = (n-1)/26;
	}
	label[i] = '\0';
	reverse(label, i);
}


int main()
{
	string str;
	char label[10];
	int n;
	str = "Z";
	cout << str << " = " << columnNumber(str) << endl;
	str = "ZZ";
	cout << str << " = " << columnNumber(str) << endl;
	str = "ADBG";
	cout << str << " = " << columnNumber(str) << endl;

	n = 26;
	columnLabel(n, label);
	cout << n << " = " << label << endl;

	n = 702;
	columnLabel(n, label);
	cout << n << " = " << label << endl;

	n = 20339;
	columnLabel(n, label);
	cout << n << " = " << label << endl;

	return 0;
}