/*

??:
*/
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>  
#include <stdbool.h>   
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define PI 3.14159265358979323846;
#define EPS 1e-10
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r)
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r)
#define TYPE long long
#define ll long long
#define MEMSET(a) memset(a,0,sizeof(a))
#define MEMSET_U(a) memset(a,-1,sizeof(a))
const int mod = (int)1e09 + 7;

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF
#define DUMMY

int in(void) { int i; scanf("%d", &i); return i; }
long long llin(void) { long long i; scanf("%lld", &i); return i; }
double din(void) { double i; scanf("%lf", &i); return i; }
void chin(char s[]) { scanf("%s", s); }

void print(int a) { printf("%d\n", a); }
void llprint(long long a) { printf("%lld\n", a); }
void dprint(double a) { printf("%.10f\n", a); }
void print2(int a, int b) { printf("%d %d\n", a, b); }
/*
int max(int a, int b) { if (a>b) { return a; }return b; }
int min(int a, int b) { if (a<b) { return a; }return b; }
*/
long long llmax(long long a, long long b) { return a > b ? a : b; }
long long llmin(long long a, long long b) { return a < b ? a : b; }
double dmax(double a, double b) { return a > b ? a : b; }
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
int char_cmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int char_cmp_r(const void *a, const void *b) { return strcmp((char *)b, (char *)a); }
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

//A
//int main() {
//	char S[100][105];
//	int i,j;
//	int r = 0, b = 0, null = 0;
//
//	int N = in();
//	rep(i, N) chin(S[i]);
//	rep(j, N) {
//		rep(i, N) {
//			if (S[j][i] == 'R')r++;
//			if (S[j][i] == 'B')b++;
//			if (S[j][i] == '.')null++;
//		}
//	}
//	if (r == b)printf("%s\n", "DRAW");
//	if (r > b)printf("%s\n", "TAKAHASHI");
//	if (r < b)printf("%s\n", "AOKI");
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//B
//char S[102];
//int len, max_i, f[102] = { 0 };
//
//int main() {
//	int N, R;
//
//	int cnt = 0, cnt_m = 0, cnt_p = 0;
//	int flg_go_p = 0, flg_p = 0;
//	int ans = -1;
//
//	scanf("%d %d", &N, &R);
//	scanf("%s", &S);
//
//	len = strlen(S);
//	for (int i = 0; i < len; i++) {
//		if (S[i] == 'o') {
//			f[i] = 1;
//		}
//		else if (S[i] == '.') {
//			f[i] = 0;
//			max_i = i;
//		}
//	}
//
//	for (int i = 0; i <= max_i - (R - 1); i++) {//?????????
//		cnt_m = i;//???????
//		flg_p = 0;
//		if (f[i] == 0) {//???????????
//			for (int j = i; j < i + R; j++) {//????
//				f[j] = 1;
//			}
//			flg_p = 1;
//			cnt_p++;//????????
//		}
//		if (f[i] == 1 && flg_p == 0 && i == max_i - (R - 1)) {//?????????????
//
//			for (int k = i; k < i + R; k++) {//?????????????????
//				if (f[k] == 0) {
//					flg_go_p = 1;
//				}
//			}
//			if (flg_go_p == 1) {
//				for (int j = i; j < i + R; j++) {//????
//					f[j] = 1;
//				}
//				flg_p = 1;
//				cnt_p++;//????????
//				flg_go_p = 0;
//			}
//		}
//	}
//
//	cnt = cnt_p + cnt_m;//?????
//	ans = cnt;
//
//	printf("%d\n", ans);
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//B;AC
int main() {
	int N, R, i, j, ans = 0;
	scanf("%d%d", &N, &R);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int r = -1;
	for (i = 0; i < N; i++) {
		if (S[i] == '.') {
			r = i;
		}
	}
	if (r == -1) {
		printf("0\n");
		return 0;
	}
	for (i = 0; i < N; i++, ans++) {
		if (S[i] == '.' || i >= r - R + 1) {
			for (j = i; j < i + R && j < N; j++) {
				S[j] = 'o';
			}
			ans++;
		}
		for (j = 0; S[j] == 'o'; j++) {}
		if (j == N) {
			printf("%d\n", ans);
			return 0;
		}
	}
} ./Main.c: In function ‘in’:
./Main.c:34:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void) { int i; scanf("%d", &i); return i; }
                       ^
./Main.c: In function ‘llin’:
./Main.c:35:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long long llin(void) { long long i; scanf("%lld", &i); return i; }
                                     ^
./Main.c: In function ‘din’:
./Main.c:36:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 double din(void) { double i; scanf("%lf", &i); return i; }
                              ^
./Main.c: In function ‘chin’:
./Main.c:37:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 void chin(char s[]) { scanf("%s", s); }
                       ^
./Main.c: In function ‘main’:
./Main.c:147:2: warning: ignoring return value of ‘...