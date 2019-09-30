#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int Test, N, M, V;
long long A[200];

int Calc()
{
	int Cnt = 0;
	sort(A, A + N);
	long long U = 0;
	for (int i = 0; i < N; i ++) {
		while (U + 1 < A[i]) {
			long long K = U + 1;
			U += K * M;
			Cnt ++;
			if (U >= V) return Cnt;
		}
		U += A[i] * M;
	}
	while (U < V) {
		long long K = U + 1;
		U += K * M;
		Cnt ++;
	}
	return Cnt;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &Test);
	for (int Case = 1; Case <= Test; Case ++) {
		scanf("%d%d%d", &M, &N, &V);
		for (int i = 0; i < N; i ++) {
			scanf("%lld", &A[i]);
		}
		printf("Case #%d: %d\n", Case, Calc());
	}
    return 0;
}

