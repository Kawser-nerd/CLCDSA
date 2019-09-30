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




int main() {
	char S[100001];
	ll ren, tmp = 0, ans = 0;
	scanf("%s", &S);
	ren = strlen(S);

	for (int i = 1; i < ren - 1; i++) {
		if (S[i] == 'U') {
			tmp += i * 2 + (ren - i - 1);
		}
		if (S[i] == 'D') {
			tmp += i + 2 * (ren - i - 1);
		}
	}

	//???
	tmp += (ren - 1) * 2;

	ans = tmp;
	printf("%ld\n", ans);


#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:66:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100001]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:82:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%ld\n", ans);
         ^
./Main.c: In function ‘in’:
./Main.c:36:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void) { int i; scanf("%d", &i); return i; }
                       ^
./Main.c: In function ‘llin’:
./Main.c:37:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long long llin(void) { long long i; scanf("%lld", &i); return i; }
                                     ^
./Main.c: In function ‘din’:
./Main.c:38:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 double din(void) { double i; scanf("%lf", ...