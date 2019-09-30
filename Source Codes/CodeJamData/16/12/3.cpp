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
int parity[2525];

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		for (int i = 0; i < 2525; ++i) parity[i] = 0;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < 2 * N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int a;
				scanf("%d", &a);
				parity[a] ^= 1;
			}
		}
		vector<int> ans;
		for (int i = 0; i < 2525; ++i) if (parity[i]) ans.push_back(i);
		sort(ans.begin(), ans.end());
		printf("Case #%d:", t);
		for (int a : ans) printf(" %d", a);
		puts("");
	}

	return 0;
}
