#include <iostream>
#include <vector>

using namespace std;

int s[10] = {0,2,5,5,4,5,6,3,7,6};

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A(M);
	for(auto &x: A) cin >> x;

	//N?K?(???????1???????N/2?)
	vector<vector<int> > dp(N / 2 + 1, vector<int> (N + 1, 0));


	for(int i = 0 ; i <= N / 2; i++) {
		for(int j = 2; j <= N; j++) {
			for(int k = 0; k < M; k++) {
				if(j - s[A[k]] < 0) continue;
				if(i == 0) dp[i][j] = j == s[A[k]] ? max(dp[i][j], A[k]) : dp[i][j];
				else if(dp[i - 1][j - s[A[k]]] != 0) dp[i][j] = max(dp[i][j], A[k]);
			}
		}
	}

	int i = N / 2, j = N;
	while(dp[i][j] == 0) i--;
	while(j > 0) {
		if(dp[i][j] == 0) break;
		cout << dp[i][j];
		j -= s[dp[i][j]];
		i--;
	}
	cout << endl;
}