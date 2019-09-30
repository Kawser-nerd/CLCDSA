#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

const int inf = 2147483647;
const double pi = acos(-1.0);
const double eps = 1e-8;

struct Food {
	long long P, S;
} food[300], f[300];

bool cmp(const Food &a, const Food &b) {
	if(a.S == b.S) return a.P > b.P;
	else return a.S < b.S;
}

long long M, F;
int N;

long long calc(long long M, long long A, long long B, long long C, long long U) {
	// choose k to maximize min( (M - A * k) / B + C * k, U * k + C * k)

	// (M - A * k) == U * k * B
	// (U*B+A)*k == M
	
	long long k = M / (U*B+A);

	long long res = 0;
	for(long long d=-100; d<=100; d++) {
		long long K = (k + d);
		if((M - A * K) < 0) continue;
		long long v = min( (M - A * K) / B + C * K, U * K + C * K );
		if(res < v) res = v;
	}
	
	long long K = M/A;
	if((M - A * K) < 0) while(1);
	long long v = min( (M - A * K) / B + C * K, U * K + C * K );
	if(res < v) res = v;
	

	return res;
}

int main() {
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C-small-attempt3.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%I64d%I64d%I64d", &M, &F, &N);
		for(int i=0; i<N; i++) {
			scanf("%I64d%I64d", &food[i].P, &food[i].S);
		}
		sort(food, food+N, cmp);
		int NN = 0;
		for(int i=0; i<N; i++) {
			while(NN!=0 && f[NN-1].P >= food[i].P) NN--;
			f[NN++] = food[i];
		}

		long long total = 0;
		long long many = 0;
		long long ans = 0;
		for(int i=0; i<NN; i++) {
			long long prize = f[i].P;
			long long last = (i>0 ? (f[i].S - f[i-1].S) : (f[i].S + 1));

			// count = (M - total * k - F * k) / prize + many * k
			// upper = k * last + k * many

			long long res = calc(M, total + F, prize, many, last);
			ans = max(ans, res);

			total += last * f[i].P;
			many += last;
		}

		printf("Case #%d: %I64d\n", test, ans);
	}
	return 0;
}
