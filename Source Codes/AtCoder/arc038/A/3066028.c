/*

??:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>	
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE int
#define MEMSET(a) memset(a,0,sizeof(a))
const int mod = (int)1e09 + 7;

int in(void) {
	int i; scanf("%d", &i);
	return i;
}
long long llin(void) {
	long long i; scanf("%lld", &i);
	return i;
}
double din(void) {
	double i; scanf("%lf", &i);
	return i;
}
void chin(char s[]) {
	scanf("%s", s);
}
void print(int a) {
	printf("%d\n", a);
}
void llprint(long long a) {
	printf("%lld\n", a);
}
void dprint(double a) {
	printf("%.10f\n", a);
}
void print2(int a, int b) {
	printf("%d %d\n", a, b);
}
//long long max(long long a, long long b) {
//	return a>b ? a : b;
//}
//long long min(long long a, long long b) {
//	return a<b ? a : b;
//}
long long llabs(long long a) {
	return a>0 ? a : -a;
}
double dmax(double a, double b) {
	return a>b ? a : b;
}
int cmp(const void *a, const void *b) {
	return *(TYPE *)a - *(TYPE *)b;
}
int cmp_r(const void *a, const void *b) {
	return *(TYPE *)b - *(TYPE *)a;
}
int char_cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}
int char_cmp_r(const void *a, const void *b) {
	return strcmp((char *)b, (char *)a);
}
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
long long gcd(long long x, long long y) {
	return x%y ? gcd(y, x%y) : y;
}
long long lcm(long long x, long long y) {
	return x / gcd(x, y)*y;
}

int main(void) {
	int n = in(), a[1000], i, ans = 0;
	rep(i, n)a[i] = in();
	sort_r(a, n);
	for (i = 0; i<n; i += 2)ans += a[i];
	print(ans);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:25:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int i; scanf("%d", &i);
         ^
./Main.c: In function ‘llin’:
./Main.c:29:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  long long i; scanf("%lld", &i);
               ^
./Main.c: In function ‘din’:
./Main.c:33:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  double i; scanf("%lf", &i);
            ^
./Main.c: In function ‘chin’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^