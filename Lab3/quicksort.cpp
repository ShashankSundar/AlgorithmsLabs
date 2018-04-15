#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>

int partition (int arr[], int n, int left, int right){
	int i = left-1; int j = left;
	int pivot = right;

	for (; j <= right-1; j++){
		if(arr[j] <= arr[pivot]){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
		
	}
		
	int temp = arr[i+1];
	arr[i+1] = arr[right];
	arr[right] = temp;

	return i + 1;
}

void quicksort(int arr[], int n, int left, int right){
	if (left < right) {
		int part = partition(arr, n, left, right);
		quicksort(arr, n, left, part-1);
		quicksort(arr, n, part+1, right);
	}
}


int main() {
	//int arr[] = {7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
	int* arr = new int [10000000];
	int n = 10000000;
	int left = 0;
	int right = n-1;
	int r;

	for (int i = 0; i < n; i++){
		r = rand() % n/100;
		arr[i] = r;
	}

	quicksort(arr, n, left, right);
	std::cout<<arr[n/2]<<std::endl;

	return 0;
}