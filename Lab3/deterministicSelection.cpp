#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

int select(std::vector<int> &arr, int k){
    if(arr.size() <= 10){
        std::sort(arr.begin(), arr.end());
        return arr[k-1];
    }
    
    std::vector<std::vector<int> > S;
    for(int i=0; i<arr.size()/5; i++){
    	std::vector<int> y;
        S.push_back(y);
    }
    int j = 0;
    for(int i=0; i < S.size(); i++){
        S[i].push_back(arr[j]);
        S[i].push_back(arr[j+1]);
        S[i].push_back(arr[j+2]);
        S[i].push_back(arr[j+3]);
        S[i].push_back(arr[j+4]);
        j+=5;
    }

    std::vector<int> x;

    for(int i=0; i < S.size(); i++){
        x.push_back(select(S[i], 3));
    }

	int v = select(x, arr.size()/10);
	std::vector<int> Sl; 
	std::vector<int> Sr;
	std::vector<int> Sv;

	for (int i = 0; i < arr.size(); i++){
		if (arr[i] < v){
			Sl.push_back(arr[i]);
		}
		else if (arr[i] > v){
			Sr.push_back(arr[i]);
		}
		else
			Sv.push_back(arr[i]);
	}

    if (k <= Sl.size()){
		return select(Sl, k);
	}
	else if (k > Sl.size() + Sv.size()){
		return select(Sr, k - Sl.size() - Sv.size());
	}
	else 
		return v;
 

}

int main() {
	//int ARR[] = {7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
	std::vector<int> arr;
	//std::vector<int> arr (ARR, ARR + sizeof(ARR) / sizeof(int));
	int k = 10000000/2;

	srand (time(NULL));
	int r;

	for (int i = 0; i < 10000000; i++){
		r = rand() % 10000000/100;
		arr.push_back(r);
	}

	int output = select(arr, k);

    std::cout<<"Median of Medians: " << output<<"\n" << std::endl;

	return 0;	
}




