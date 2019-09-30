#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>

using namespace std;

const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int maxn = 10000 + 50;
const int maxm = 1000000 + 50;

struct node {
	long long a, b, c;
} N[maxn];

bool cmp(const node &x, const node &y) {
	return x.a * y.b > y.a * x.b;
}

int n, m;
long long k;

node T[maxm];
double A[maxm], B[maxm];
double X[maxm], Y[maxm], Z[maxm];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%I64d", &n, &k);
		fprintf(stderr, "%d\n", test);

		m = 1;
		for(int i=0; i<n; i++) {
			scanf("%I64d/%I64d %I64d", &N[i].a, &N[i].b, &N[i].c);

			for(int j=0; j<N[i].c; j++) {
				T[m++] = N[i];
			}
		}

		m--;

		sort(T+1, T+m+1, cmp);

		A[0] = 0; B[0] = 1;
		for(int i=1; i<=m; i++) {
			double u = 1.0 * T[i].a / T[i].b;
			A[i] = A[i-1] * (1-u) + B[i-1] * (1-u);
			B[i] = B[i-1] * u;
		}

		X[m+1] = 1;
		Y[m+1] = 0;
		Z[m+1] = 1;

		for(int i=m; i>=1; i--) {
			double u = 1.0 * T[i].a / T[i].b;

			Z[i] = Z[i+1] * u;
			Y[i] = X[i+1] * (1-u) + Y[i+1] * u;
			X[i] = X[i+1] * (1-u);
		}

		double res = 0;

		for(int u=0; u<=k; u++) {
			double ans = A[u] * X[m-(k-u)+1] + B[u] * Y[m-(k-u)+1] + B[u] * Z[m-(k-u)+1];

			if(ans > res) res = ans;
		}

		printf("Case #%d: %.10lf\n", test, 1-res);
	}
	return 0;
}