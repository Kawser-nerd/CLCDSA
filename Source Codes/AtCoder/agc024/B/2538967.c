#define _CRT_SECURE_NO_WARNINGS

/* include ***********************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/* define *************************/
//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)
#define FOR(i,s,n) for(int i=(int)(s),i##_len=(int)(n);i<i##_len;i++)

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

#define INF 1e9

typedef long long ll;


int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};

int p[200000];
int par[200001];
int f[200001];
int cnt[200001];

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
int Max(int a, int b) {
	return (a) > (b) ? (a) : (b);
}
void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int dfs(int x) {
	if (x == par[x]) {
		return x;
	}
	else {
		par[x] = dfs(par[x]);
		return par[x];
	}
}

int main() {
	int n;
	//*
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &p[i]);
	}
	/*/
	n = 2e5;
	REP(i, n) {
		p[n - 1 - i] = i + 1;
	}
	//*/
	REP(i, n+1) {
		par[i] = i;
		f[i] = 0;
		cnt[i] = 0;
	}
	REP(i, n) {
		f[p[i]]++;
		if (f[p[i] - 1]) {
			par[p[i]] = dfs(p[i]-1);
		}
	}
	REPS(i, n) {
		cnt[par[i]]++;
	}
	int max = 0;
	REPS(i, n) {
		if (cnt[i] > max)max = cnt[i];
	}
	PRINTD(n - max);
} ./Main.c: In function ‘main’:
./Main.c:68:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:70:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^