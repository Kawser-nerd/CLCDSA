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
/*
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r)
*/
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
int Max(int a, int b) { if (a > b) { return a; }return b; }
int Min(int a, int b) { if (a < b) { return a; }return b; }
long long llmax(long long a, long long b) { return a > b ? a : b; }
long long llmin(long long a, long long b) { return a < b ? a : b; }
double dmax(double a, double b) { return a > b ? a : b; }
double dmin(double a, double b) { return a < b ? a : b; }
//long long llmax(long long a, long long b) { return a > b ? a : b; }
//long long llmin(long long a, long long b) { return a < b ? a : b; }
//double dmax(double a, double b) { return a > b ? a : b; }
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
int char_cmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int char_cmp_r(const void *a, const void *b) { return strcmp((char *)b, (char *)a); }
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int ABS(int a) { return a >= 0 ? a : -a; }


//A
//int main() {
//	ll A, B, ans;
//	int tmp = 0;
//	scanf("%lld%lld", &A, &B);
//	if ((A < 0 && B > 0) || (A > 0 && B < 0)) {
//		tmp = 1;
//	}
//		ans = B - A -tmp;
//	printf("%ld\n", ans);
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//B
#define max_size (int)(1e5)
int main() {
	int N, i, n, w, d, l;
	scanf("%d", &N);
	int *R = (int *)malloc(sizeof(int) * N);
	int *H = (int *)malloc(sizeof(int) * N);
	int **num = (int **)malloc(sizeof(int *) * (max_size + 1));
	for (i = 0; i <= max_size; i++) {
		num[i] = (int *)malloc(sizeof(int) * 3);
		num[i][0] = 0;
		num[i][1] = 0;
		num[i][2] = 0;
	}
	int *sum = (int *)malloc(sizeof(int) * (max_size + 1));
	for (n = 0; n < N; n++) {
		scanf("%d %d", &R[n], &H[n]);
		H[n]--;
		num[R[n]][H[n]]++;
	}
	sum[0] = 0;
	for (i = 1; i < max_size; i++) {
		sum[i] = sum[i - 1] + num[i][0] + num[i][1] + num[i][2];
	}

	for (n = 0; n < N; n++) {
		w = sum[R[n] - 1] + num[R[n]][(H[n] + 1) % 3];
		d = num[R[n]][H[n]] - 1;
		l = N - w - d - 1;
		printf("%d %d %d", w, l, d);
		printf("\n");
	}

#ifdef DEBUGF
getch();
#endif
return 0;
} ./Main.c: In function ‘in’:
./Main.c:36:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void) { int i; scanf("%d", &i); return i; }
                       ^
./Main.c: In function ‘llin’:
./Main.c:37:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long long llin(void) { long long i; scanf("%lld", &i); return i; }
                                     ^
./Main.c: In function ‘din’:
./Main.c:38:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 double din(void) { double i; scanf("%lf", &i); return i; }
                              ^
./Main.c: In function ‘chin’:
./Main.c:39:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 void chin(char s[]) { scanf("%s", s); }
                       ^
./Main.c: In function ‘main’:
./Main.c:82:2: warning: ignoring return value of ‘s...