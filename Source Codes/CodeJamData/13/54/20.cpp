#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

bool v[1<<20][20];
double dp[1<<20][20];

double Exp(int B, int n){
	if (B == (1<<n) - 1) return 0;
	if (v[B][n]) return dp[B][n];
	v[B][n] = 1;
	dp[B][n] = 0;
	FOR(i,0,n){
		int t = i, cost = n;
		while ((1<<t) & B){
			t = (t + 1) % n;
			--cost;
		}
		dp[B][n] += (Exp(B + (1<<t), n) + cost) / (double)n;
	}
	return dp[B][n];
}

char s[25];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%s", s);
	int n = strlen(s);
	int B = 0;
	FOR(i,0,n) if (s[i] == 'X') B += (1 << i);
	printf("%.9f\n", Exp(B, n));
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
