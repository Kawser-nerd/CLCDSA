#include <iostream>
#include <cmath>

constexpr int MAX_N = 100000;

int N;
int A[MAX_N];

int main(){

	std::cin >> N;

	int sum = 0;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
		if(i == 0 || i == N - 1){
			sum += abs(A[i]);
		}

		if(i > 0){
			sum += abs(A[i - 1] - A[i]);
		}
	}

	for(int i = 0; i < N; ++i){
		int tsum = sum;
		if(i == 0){
			tsum -= abs(A[i]) + abs(A[i] - A[i + 1]);
			tsum += abs(A[i + 1]);
		}
		else if(i == N - 1){
			tsum -= abs(A[i - 1] - A[i]) + abs(A[i]);
			tsum += abs(A[i - 1]);
		}
		else{
			tsum -= abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1]);
			tsum += abs(A[i - 1] - A[i + 1]);
		}

		std::cout << tsum << std::endl;
	}

	return 0;
}