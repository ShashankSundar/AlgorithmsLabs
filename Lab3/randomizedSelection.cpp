#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>

int randomizedSelection(std::vector<int> arr, int k){
	srand (time(NULL));
	int v = rand() % arr.size();
	v = arr[v];
	std::vector<int> Sl; 
	std::vector<int> Sr;

	for (int i = 0; i < arr.size(); i++){
		if (arr[i] < v){
			Sl.push_back(arr[i]);
		}
		else if (arr[i] > v){
			Sr.push_back(arr[i]);
		}
	}

	if (k <= Sl.size()){
		return randomizedSelection(Sl, k);
	}
	else if (k > arr.size() - Sr.size()){
		return randomizedSelection(Sr, k - (arr.size() - Sr.size()));
	}
	else 
		return v;
}

int main() {
	//int ARR[] = {7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
	//int k = 10000000/2;
	//std::vector<int> arr (ARR, ARR + sizeof(ARR) / sizeof(int));

	std::vector<int> arr;
	int k = 10000000/2;

	srand (time(NULL));
	int r;

	for (int i = 0; i < 10000000; i++){
		r = rand() % 10000000/100;
		arr.push_back(r);
	}

	std::cout<<randomizedSelection(arr, k)<<std::endl;

	return 0;	
}





