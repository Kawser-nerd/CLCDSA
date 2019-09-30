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

int MAX(int a, int b) { if (a > b) { return a; }return b; }
/*
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

//A:AC
//int main() {
//	int A = in();
//	int B = in();
//	int c;
//	int d;
//	int flg = 0;
//
//	for (c = 1; c <= 3; c++) {
//		d = (A*B*c) % 2;
//		if (d == 1) { flg = 1; }
//	}
//	if (flg) {
//		printf("%s\n", "Yes");
//	}
//	else {
//		printf("%s\n", "No");
//	}
//
//
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//	}

//B:AC
//int main() {
//
//	char w[100][11];
//	int n, i, j;
//	scanf("%d", &n);
//	for (i = 0; i<n; ++i)scanf("%s", w[i]);
//	for (i = 0; i<n - 1; ++i) {
//		for (j = i + 1; j<n; ++j) {
//			if (!strcmp(w[i], w[j])) {
//				puts("No");
//				return 0;
//			}
//		}
//	}
//	for (i = 1; i<n; ++i) {
//		if (w[i - 1][strlen(w[i - 1]) - 1] != w[i][0]) {
//			puts("No");
//			return 0;
//		}
//	}
//	puts("Yes");
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//	}

//C:AC
///// /////////////////////////////////////////////
///// <summary> 
///// ??????????
/////?????????????????a,b??????????
/////???: ??????(??????????????-1)
///// </summary> 
///// /////////////////////////////////////////////
//int euclid(int a, int b)
//{
//	int temp;
//	if (a < b) { temp = a; a = b; b = temp; }
//	if (b < 1) return -1;
//	if (a % b == 0) return b;
//	return euclid(b, a % b);
//}
//
//int main() {
//	int N, X,A[100000];
//	int a, b,ans;
//	scanf("%d%d", &N, &X);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &A[i]);
//	}
//	a = abs(X - A[0]);
//	if (N > 1) {
//		for (int i = 0; i < N-1; i++) {
//			b = abs(X - A[i+1]);
//			a = euclid(a, b);
//		}
//	}
//	ans = a;
//	print(a);
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//D
int A[500][500] = { 0 };
int ans[250000][4] = { 0 };

int main() {
	int H, W;
	int n = 0;
	scanf("%d%d", &H, &W);
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			scanf("%d", &A[h][w]);
		}
	}

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W - 1; w++) {
			if (A[h][w] % 2) {
				ans[n][0] = h + 1;
				ans[n][1] = w + 1;
				ans[n][2] = h + 1;
				ans[n][3] = w + 2;
				A[h][w + 1] += A[h][w];
				n++;
			}
		}
	}
	for (int h = 0; h < H - 1; h++) {
		if (A[h][W - 1] % 2) {
			ans[n][0] = h + 1;
			ans[n][1] = W;
			ans[n][2] = h + 2;
			ans[n][3] = W;
			A[h + 1][W - 1] += A[h][W - 1];
			n++;
		}
	}

	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}

#ifdef DEBUGF
	getch();
#endif
	return 0;
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
./Main.c:160:2: warning: ignoring return value of ‘...