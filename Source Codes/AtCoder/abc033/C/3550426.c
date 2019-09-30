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
//
//	char N[5];
//	int check = 0;
//		scanf("%s", &N);
//	if (N[0] == N[1] && N[1] == N[2] && N[2] == N[3]) {
//		puts("SAME");
//		return 0;
//	}
//	else {
//		puts("DIFFERENT");
//		return 0;
//	}
//
//#ifdef DEBUGF
//getch();
//#endif
//return 0;
//}

//B
//int main() {
//	int  N;
//	char S[1000][21];
//	int P[1000];
//	int n;
//	int ptotal = 0;
//	scanf("%d", &N);
//	for (n = 0; n < N; n++) {
//		scanf("%s%d", &S[n], &P[n]);
//		ptotal += P[n];
//	}
//	for (n = 0; n < N; n++) {
//		if (P[n] * 2 > ptotal) {
//			printf("%s\n", S[n]);
//			return 0;
//		}
//	}
//	puts("atcoder");
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//C ??
char S[100005];

int jadge(int l,int r) {
	int z = 0;
	for (int i = l; i <= r; i += 2) {
		if (S[i] == '0') {//0?????1???
			z = 1;
			break;
		}
	}
	return z;
}
int main() {
	scanf("%s", S);
	int len = strlen(S);
	S[len] = '+';//??????????????
	S[len+1] = '\0';//??????????????????

	int l = 0;
	int ans = 0;
	for (int i = 0; S[i] != '\0'; i++) {
		if (S[i] == '+') {//'+'????????????[l,r]??0??????????
			if (jadge(l, i - 1) == 0) {//??[l,r]??0????
				ans++;
			}
			l = i + 1;//????
			i= l;//????
		}
	}
	printf("%d\n", ans);

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
./Main.c:123:2: warning: ignoring return value of ‘...