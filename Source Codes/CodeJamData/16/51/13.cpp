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
char S[20202];
int N;

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%s", S);
		N = strlen(S);

		stack<char> T;
		int sco = 0;
		int ps = 0;
		for (int i = 0; i < N; ++i) {
			if (T.size() == 0 || T.top() != S[i]) {
				T.push(S[i]);
				++ps;
			}  else {
				sco += 10;
				T.pop();
				--ps;
			}
		}

		int L = ps / 2;
		int ans = sco + L * 5;
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
