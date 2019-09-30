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
#define bool    _Bool
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

int check(char A[64][64], char B[64][64], int i, int j, int m) {
	int x, y;
	for (x = 0; x < m; x++) {
		for (y = 0; y < m; y++) {
			if (A[i + x][j + y] != B[x][y]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int N, M;
	int i, j;
	int flag = 0;

	scanf("%d%d", &N, &M);
	char A[50][51], B[50][51];
	for (int i = 0; i < N; i++) {
		scanf("%s", &A[i][0]);
	}
	for (int k = 0; k < M; k++) {
		scanf("%s", &B[k][0]);
	}

	for (i = 0; i < N - (M - 1); i++) {
		for (j = 0; j < N - (M - 1); j++) {
			flag = check(A, B, i, j, M);
			if (flag) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");




#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:86:17: warning: passing argument 1 of ‘check’ from incompatible pointer type [-Wincompatible-pointer-types]
    flag = check(A, B, i, j, M);
                 ^
./Main.c:58:5: note: expected ‘char (*)[64]’ but argument is of type ‘char (*)[51]’
 int check(char A[64][64], char B[64][64], int i, int j, int m) {
     ^
./Main.c:86:20: warning: passing argument 2 of ‘check’ from incompatible pointer type [-Wincompatible-pointer-types]
    flag = check(A, B, i, j, M);
                    ^
./Main.c:58:5: note: expected ‘char (*)[64]’ but argument is of type ‘char (*)[51]’
 int check(char A[64][64], char B[64][64], int i, int j, int m) {
     ^
./Main.c: In function ‘in’:
./Main.c:34:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void) { int i; scanf("%d", &i); return i; }
                       ^
./Main.c: In function ‘llin’:
./Main.c:35:37: warning: ignoring return value of ‘scanf’, declared with attrib...