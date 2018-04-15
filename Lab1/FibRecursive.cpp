#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>

int fib1(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib1(n-1) + fib1(n-2);
}


int main(int argc, char *argv[]) {
	int n;
	std::istringstream ss(argv[1]);
	ss >> n;
	n = fib1(n);

	std::cout<<n<<std::endl;

	return 0;
}

