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
int N, L;
string G[105], B;

char in[55];
int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; ++i) {
			scanf("%s", in);
			G[i] = in;
		}
		scanf("%s", in);
		B = in;

		string P, Q;
		for (int i = 0; i < N; ++i) {
			if (G[i] == B) goto impossible;
		}

		for (int i = 0; i < B.size(); ++i) {
			P.push_back(B[i] ^ 1);
			P.push_back('?');
		}
		for (int i = 0; i < B.size(); ++i) {
			Q.push_back(B[i] ^ 1);
			if (i != B.size() - 1) Q.push_back(B[i]);
		}
		printf("Case #%d: %s %s\n", t, P.c_str(), Q.c_str());
		continue;
	impossible:
		printf("Case #%d: IMPOSSIBLE\n", t);
	}

	return 0;
}
