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
int N, B, M[1010];

pair<i64, vector<int> > check(i64 t2)
{
	i64 ret = 0;
	vector<int> ret2;

	for (int i = 0; i < B; ++i) {
		ret += (t2 + M[i] - 1) / M[i];
		if (t2 % M[i] == 0) ret2.push_back(i + 1);
	}

	return make_pair(ret, ret2);
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &B, &N);
		for (int i = 0; i < B; ++i) scanf("%d", M + i);
		
		i64 left = 0, right = 1LL << 62LL;
		while (left < right) {
			i64 mid = (left + right) / 2;

			auto t = check(mid);

			if (t.first + t.second.size() < N) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		auto rt = check(left);
		int sol = rt.second[N - (int)rt.first - 1];
		printf("Case #%d: %d\n", t, sol);
	}

	return 0;
}
