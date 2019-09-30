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
//
//	char S[6];
//	int N;
//	int a, b;
//	char ans[3];
//
//	scanf("%s", S);
//	scanf("%d", &N);
//
//	a = N / 5;
//	if (N % 5 == 0) {
//		a = a - 1;
//		b = 4; 
//	}
//	else {
//		b = N % 5 - 1;
//	}
//
//	printf("%c%c\n", S[a], S[b]);
//
//#ifdef DEBUGF
//	getch();
//#endif
//
//	return 0;
//}


//B
int main() {

	int N, A, B, D[101];
	char S[101][5];

	int vec[101] = { 0 };//??
	int pos = 0;//??
	int flg = 0;

	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < N; i++) {
		scanf("%s", &S[i]);
		scanf("%d", &D[i]);
	}

	for (int i = 0; i < N; i++) {
		flg = 0;
		if (S[i][0] == 'E') { vec[i] = -1; }
		else if (S[i][0] == 'W') { vec[i] = 1; }

		if (D[i] >= A && D[i] <= B) {
			pos += vec[i] * D[i];
			flg = 1;
		}
		else if (D[i] < A) {
			pos += vec[i] * A;
			flg = 1;
		}
		else if (D[i] > B) {
			pos += vec[i] * B;
			flg = 1;
	}
}

 	if (pos < 0) {
		printf("%s", "East"); 
		printf(" %d\n", abs(pos));
	}
	else if (pos > 0) {
		printf("%s", "West"); 
		printf(" %d\n", abs(pos));
	}
	else if (pos == 0) { printf("%s\n", "0"); }

#ifdef DEBUGF
	getch();
#endif
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:98:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
   scanf("%s", &S[i]);
         ^
./Main.c: In function ‘in’:
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
./Main.c:37:23: warning: ignoring return value of ‘scanf’, declared with attribute...