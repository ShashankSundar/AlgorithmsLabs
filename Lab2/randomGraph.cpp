#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <sstream>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>


int largestComponent (int ** graph, int start, int n, int t) {

	std::vector<bool> visited(n, false);
    std::queue<int> Q;

    Q.push(start);
	visited[start] = true;
	int count = 1;

	while(!Q.empty()){
	    int u = Q.front(); Q.pop();

	    for (int v = 0; v < n; v++){
	        if(graph[u][v] == 1 && (!visited[v])){
	            Q.push(v);
	            visited[v] = true;
	            count++;
	        }
	    }
	}

    if (count >= t)
    	return 1;

	return 0;
}


int ** randGraph (int n, double p) {

	int** graph = 0;
    graph = new int*[n];
	
	for (int i = 0; i < n; i++){
		graph[i] = new int [n];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j != i) {
				double q = (double) rand() / (RAND_MAX);
				if (q < p){
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}
		}	
	}

	// std::cout<<std::endl; std::cout<<std::endl;

	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++){
	// 		std::cout<<graph[i][j];
	// 	}
	// 	std::cout<<std::endl;
	// }

	return graph;
}

int main() {
	int n = 40;
	int t = 30;
	double p;
	double c[15];
	c[0] = .2;
	for (int i = 1; i < 15; i++) 
		c[i] = c[i-1] + .2;

	std::srand (std::time (0));

	int correct = 0;

	double output[15];

	for (int i = 0; i < 15; i++){
		p = c[i]/n;
		for (int j = 0; j < 500; j++){
			int ** graph = randGraph(n, p);
			for (int k = 0; k < n; k++){
				if (largestComponent(graph, k, n, t) == 1){
					correct++;
					k = n;
				}
			}
		}
		output[i] = ((double)correct/500)*100;
		correct = 0;
	}

	for (int i = 0; i < 15; i++){
		std::cout<<output[i]<<std::endl;
	}

	// int ** graph = randGraph(n, p);
	// int isThere = 0;

	// for (int i = 0; i < n; i++){
	// 	isThere = largestComponent(graph, i, n, t);
	// 	if (isThere == 1){
	// 		std::cout<<"This graph has a connected component of "<<t<<" vertices"<<std::endl;
	// 		break;
	// 	}
	// }
	// if (isThere == 0){
	// 		std::cout<<"This graph has no connected component of "<<t<<" vertices"<<std::endl;
	// 	}


	return 0;
}