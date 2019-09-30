#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T, N;
double Y;
ll P[1000];
double S[1000];
bool done[1000];

double res;

void visit(double t, double p, int don) {
	if (t > res)
		return;
	if (don == N) {
		res = min(res, t);
		return;
	}
	{
	double mint = 1e10;
	int mini = -1;
	REP(i,0,N) {
		if (!done[i] && P[i] > 0) {
// 			printf("chk1 %d\n", i);
			assert(p <= P[i]+S[i]*t+1e-9);
			double h = (P[i]+S[i]*t-p)/(Y-S[i]) + t;
			if (mint > h) {
				mint = h;
				mini = i;
			}
		}
	}
	if (mini != -1) {
// 		printf("right %lf %lf %d\n", mint, p+Y*mint, mini);
		done[mini] = true;
		visit(mint, p+Y*(mint-t), don+1);
		done[mini] = false;
// 		return;
	}
	}
	{
	double mint = 1e10;
	int mini = -1;
	REP(i,0,N) {
		if (!done[i] && P[i] < 0) {
// 			printf("chk2 %d %lf %lf\n", i, P[i]-S[i]*t, p);
			assert(p >= P[i]-S[i]*t-1e-9);
			double h = (p-(P[i]-S[i]*t))/(Y-S[i]) + t;
			if (mint > h) {
				mint = h;
				mini = i;
			}
		}
	}
	if (mini != -1) {
// 		printf("left %lf %lf %d\n", mint, p-Y*mint, mini);
		done[mini] = true;
		visit(mint, p-Y*(mint-t), don+1);
		done[mini] = false;
	}
	}
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%lf%d", &Y, &N);
		REP(n,0,N) {
			scanf("%lld", &P[n]);
		}
		REP(n,0,N) {
			scanf("%lf", &S[n]);
			done[n] = false;
		}
		res = 1e10;
		visit(0, 0, 0);
		printf("%.9lf\n", res);
	}
	return 0;
}
