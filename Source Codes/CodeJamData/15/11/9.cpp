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
int N, Mi[1010];

int met1()
{
	int ret = 0;
	for (int i = 1; i < N; ++i) ret += max(0, Mi[i - 1] - Mi[i]);
	return ret;
}

int met2()
{
	int md = 0;
	for (int i = 1; i < N; ++i) md = max(md, Mi[i - 1] - Mi[i]);

	int ret = 0;
	for (int i = 1; i < N; ++i) {
		ret += min(md, Mi[i - 1]);
	}
	return ret;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", Mi + i);

		printf("Case #%d: %d %d\n", t, met1(), met2());
	}

	return 0;
}
