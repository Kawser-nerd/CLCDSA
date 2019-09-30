#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long field[101][101];
long n;
long x[105], y[105], h[105];

int main(){
	bool flag = true;
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		scanf("%ld %ld %ld", &x[i], &y[i], &h[i]);
	}
	for(int i = 0; i < n; i++){
		if(h[i] != 0){
			for(int j = 0; j <= 100; j++){
				for(int k = 0; k <= 100; k++){
					field[j][k] = h[i] + std::abs(j - x[i]) + std::abs(k-y[i]);
				}
			}
			break;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 100; j++){
			for(int k = 0; k <= 100; k++){
				if(h[i] != std::max(field[j][k] - std::abs(x[i] - j) - std::abs(y[i] - k), (long)0)){
					field[j][k] = 0;
				}
			}
		}
	}
	/*
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j <= 100; j++){
			for(int k = 0; k <= 100; k++){
				if(std::abs(std::abs((j-x[i]) + (k-y[i])) - std::abs((j-x[i+1]) + (k-y[i+1]))) != std::abs(h[i] - h[i+1])){
					field[j][k] = false;
				}
			}
		}
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			printf("%ld ", field[i][j]);
		}
		printf("\n");
	}
	//*/
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(field[i][j] != 0){
				printf("%d %d %ld\n", i, j, field[i][j]);
			}
		}
	}
	return 0;
	
}