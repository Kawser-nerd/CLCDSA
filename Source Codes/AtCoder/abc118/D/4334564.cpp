#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define INF (INT32_MAX)

using namespace std;

int match[9] = {2,5,5,4,5,6,3,7,6};

int main()
{
	int N,M;
	cin >> N >>  M;

	vector<int> input(M);
	for (int i = 0; i < M; i++){
		cin >> input[i];
	}
	sort(input.begin(),input.end(),greater<int>()); //?????	

	//dynamic programing
	//dp[i]:????i???????????????????????
	std::vector<int> dp(N+1,-INF);
	dp[0] = 0;

	for (int i = 1; i <= N; i++){
		//i????????????????????????Aj????
		for (int j = 0; j < M; j++){
			int a = input[j]-1;
			int n = match[a];
			if(i >= n){
				dp[i] = max( dp[i] , dp[i-n]+1 );
			}
		}
	}

	int d = dp[N];
	std::vector<int> ans;

	for (int i = 0; i < d; i++){
		for (int j = 0; j < M; j++){
			int a = input[j]-1;
			int n = match[a];

			if( N-n >=0 && dp[N-n] == dp[N] -1){
				ans.push_back(input[j]);
				N -= n;
				break;
			}
		}	
	}

	for (int i = 0; i < d; i++){
		cout << ans[i];
	}

	cout << "\n";

	return 0;
}