/*
STRING & FILE

This is a code that sums up integers from a text file, one int per line.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int string2int(string &s){
	int ret = 0, i =0;
	while(s[i]){
		ret*=10;
		ret += (s[i++]-'0');
	}
	return ret;
}

int main(){
	string line;
	int nn, sum=0;

	ifstream myFile("mytext.txt", ios_base::in);
	
	while(getline(myFile, line)){
		//stringstream ss(line);
		//ss >> nn;
		nn = string2int(line);
		sum += nn;
	}
	cout << "The sum is: " << sum << endl;
	
	return 0;
}