#include <iostream>
#include <algorithm>

constexpr int MAX_N = 100;

int N;
int A[2][MAX_N], csum[2][MAX_N];

int main(){

	std::cin >> N;

	for(int i = 0; i < 2; ++i){
		for (int j = 0; j < N; ++j){
			std::cin >> A[i][j];
			if(j != 0){
				csum[i][j] = csum[i][j - 1] + A[i][j];
			}
			else{
				csum[i][j] = A[i][j];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; ++i){
		if(i != 0){
			ans = std::max(ans, csum[0][i] + csum[1][N - 1] - csum[1][i - 1]);
		}
		else{
			ans = std::max(ans, csum[0][i] + csum[1][N - 1]);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}