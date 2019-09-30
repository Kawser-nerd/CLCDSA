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

int a[200000];

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

int main() {
	int n;
	//*
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
	}
	/*/
	n = 2e5;
	REP(i, n) {
		a[i] = i;
	}
	FOR(i, 1e5, n)a[i] = 1e5;
	//*/
	REP(i, n) {
		if (a[i] > i) {
			puts("-1");
			return 0;
		}
		if (i > 0) {
			if (a[i] > a[i - 1] + 1) {
				puts("-1");
				return 0;
			}
		}
	}
	ll cnt=0;
	REP(i, n) {
		if (i == 0)continue;
		if (a[i] <= a[i - 1]) {
			cnt += a[i - 1];
		}
		if (i == n - 1) {
			cnt += a[i];
		}
	}
	PRINTL(cnt);
} ./Main.c: In function ‘main’:
./Main.c:55:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^