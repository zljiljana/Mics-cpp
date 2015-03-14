/*
Merge sort on vectors.
*/
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
	for(int i = 0; i < v.size(); i++) 
		cout << v[i] << " ";
	cout << endl;
}

vector<int> merge(vector<int> left, vector<int> right){
	vector<int> result;
	while (left.size()>0 || right.size() > 0){
		if (left.size()>0 && right.size() > 0){
			if(left.front() <= right.front()){
				result.push_back(left.front());
				left.erase(left.begin());
			} else {
				result.push_back(right.front());
				right.erase(right.begin());
			}
		} 
		else {
			while(left.size() > 0){
				result.push_back(left.front());
				left.erase(left.begin());
			}
			while(right.size() > 0){
				result.push_back(right.front());
				right.erase(right.begin());
			}
		}
	}
	return result;
}

vector<int> mergeSort(vector<int> v){
	if(v.size() <= 1)
		return v;
	vector<int> left, right, result;
	
	int mid = v.size()/2;

	for (int i=0;i<mid;i++)
		left.push_back(v[i]);

	for (int i=mid;i<(int)v.size();i++)
		right.push_back(v[i]);

	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left, right);
	return result;
}


int main()
{
   vector<int> v;

   v.push_back(38);
   v.push_back(27);
   v.push_back(43);
   v.push_back(3);
   v.push_back(9);
   v.push_back(82);
   v.push_back(10);
   v.push_back(1);

   print(v);
   cout << "----" << endl;
   v = mergeSort(v);
   print(v);

   return 0;
}