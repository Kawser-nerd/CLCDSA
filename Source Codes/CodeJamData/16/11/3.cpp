#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
char S[1010];
string dp[1010];

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%s", S);
		dp[0] = string("");
		int N = strlen(S);
		for (int i = 1; i <= N; ++i) {
			dp[i] = "1";
			string cand1 = dp[i - 1];
			cand1.push_back(S[i - 1]);
			dp[i] = max(dp[i], cand1);
			string cand2 = dp[i - 1];
			cand2.insert(cand2.begin(), S[i - 1]);
			dp[i] = max(dp[i], cand2);
		}

		printf("Case #%d: %s\n", t, dp[N].c_str());
	}

	return 0;
}
