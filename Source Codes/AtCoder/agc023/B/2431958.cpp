#include <iostream>
#include <string>

constexpr int MAX_N = 300;

int N;
std::string col[MAX_N];
std::string row[MAX_N];

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> col[i];
		col[i] = col[i] + col[i];
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			row[i] += col[j][i];
		}
		row[i] = row[i] + row[i];
	}

	int ans = 0;
	int memo[MAX_N * 2][MAX_N * 2] = {}; //0:Unknown 1:OK 2:NG
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			bool flag = true;
			for(int k = 0; k < N; ++k){
				if(memo[i + k][j + k] == 1){
					continue;
				}
				if(memo[i + k][j + k] == 2){
					flag = false;
					break;
				}
				if(col[(k + j) % N].substr(i, N) != row[(k + i) % N].substr(j, N)){
					memo[i + k][j + k] = 2;
					flag = false;
					break;
				}
				memo[i + k][j + k] = 1;
			}
			if(flag){
				++ans;
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}