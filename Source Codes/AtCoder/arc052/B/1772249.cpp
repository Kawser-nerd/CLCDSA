#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int N, Q;
	cin >> N >> Q;
	
	double sum[30000] = {};
	
	for(int i = 0; i < N; i++){
		double X, R, H;
		cin >> X >> R >> H;
		for(int i = X + H - 1; i >= X; i--){
			double h = X - i + H;
			sum[i] += (R * h / H) * (R * h / H) * h / 3 * M_PI;
			h = X - i + H - 1;
			sum[i] -= (R * h / H) * (R * h / H) * h / 3 * M_PI;
		}
	}
	
	for(int i = 30000 - 2; i >= 0; i--){
		sum[i] += sum[i + 1];
	}
	
	for(int i = 0; i < Q; i++){
		int A, B;
		cin >> A >> B;
		printf("%.6f\n", sum[A] - sum[B]);
	}
	
	return 0;
}