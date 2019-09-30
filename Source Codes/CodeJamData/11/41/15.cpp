#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)

int T;
int lk[1001];
int wk[1001];

int main() {
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int X, S, R, t, N;
		scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
		int lges = 0;
		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d %d %d", &a, &b, &wk[i]);
			lk[i] = b-a;
			lges += b-a;
		}
		lk[N] = X-lges;
		wk[N] = 0;
		N++;
		long double erg = 0;
		vector<pair<long double, long double> > vec;
		for (int i = 0; i < N; i++) {
			vec.push_back(make_pair((long double)(S-R)/(wk[i]+S), (long double)lk[i]/(wk[i]+R)));
			erg += (long double)lk[i]/(wk[i]+S);
		}
		sort(vec.begin(), vec.end());
		long double rt = t;
		for (int i = 0; i < N && rt > 0; i++) {
			long double dt = min(rt, vec[i].second);
			rt -= dt;
			erg += dt*vec[i].first;
		}
		printf("%.15Lf\n", erg);
	}
	return 0;
}
