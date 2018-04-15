#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>

int fib2(int n) {
	if (n == 0)
		return 0;
	int f[n+1];
	for (int k = 0; k < 1000000; k++){
		f[0] = 0; f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i-1] + f[i-2];
		}
	}

	return f[n];
}


int main(int argc, char *argv[]) {
	int n;
	std::istringstream ss(argv[1]);
	ss >> n;
	n = fib2(n);

	std::cout<<n<<std::endl;

	return 0;
}