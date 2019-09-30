#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <iostream>
#include <queue>
#include <set>
#include <map>

#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define SS stringstream
#define LL long long
#define LD long double
#define SZ(x) int(x.size())
#define ALL(x) x.begin(),x.end()
#define FOR(a,b) for(int a=0;a<b;a++)
#define DFOR(a,b) for(int a=b-1;a>=0;a--)
#define CLR(a,b) memset(a,b,sizeof(a))

using namespace std;


struct SLE {
	int n, m; 
	vector<vector<double> > a;
	SLE(int N, int M) { a.resize(n=N); m=M; FOR(i, n) a[i].resize(m); }
	void eliminate() {
		FOR(i, m-1) {
			int t = i;
			for (int j = i+1; j < n; j++) if (ABS(a[j][i]) > ABS(a[t][i])) t = j;
			swap(a[i], a[t]);
			for (int j = m-1; j >= i; j--) a[i][j] = a[i][j] / a[i][i];
			FOR(I, n) for (int J = m-1; J >= i; J--) if (I!=i) a[I][J] = a[I][J] - a[I][i] * a[i][J];
		}
	}
};

double x[3], y[3], X[3], Y[3];

void solvecase() {
	for (int i = 0; i < 3; i++) scanf("%lf%lf", &x[i], &y[i]);
	for (int i = 0; i < 3; i++) scanf("%lf%lf", &X[i], &Y[i]);
	SLE s1(6, 7);
	for (int i = 0; i < 3; i++) {
		s1.a[2*i][0] = x[i];
		s1.a[2*i][1] = y[i];
		s1.a[2*i][2] = 1.0;
		s1.a[2*i+1][3] = x[i];
		s1.a[2*i+1][4] = y[i];
		s1.a[2*i+1][5] = 1.0;
		s1.a[2*i][6] = X[i];
		s1.a[2*i+1][6] = Y[i];
	}
	s1.eliminate();
	double a = s1.a[0][6];
	double b = s1.a[1][6];
	double c = s1.a[2][6];
	double d = s1.a[3][6];
	double e = s1.a[4][6];
	double f = s1.a[5][6];
	SLE s2(2,3);
	s2.a[0][0] = a-1;
	s2.a[0][1] = b;
	s2.a[0][2] = -c;
	s2.a[1][0] = d;
	s2.a[1][1] = e-1;
	s2.a[1][2] = -f;
	s2.eliminate();
	printf("%.8lf %.8lf", s2.a[0][2], s2.a[1][2]);
}

void solve() {
	int n;
	scanf("%d\n", &n);
	FOR(i, n) {
		printf("Case #%d: ", i+1);
		solvecase();
		printf("\n");
	}
}

int main() {
	freopen("y", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	solve();
	return 0;
}