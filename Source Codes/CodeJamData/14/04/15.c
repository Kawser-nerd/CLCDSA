#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")

#include <algorithm>
using namespace std;

double as[11111];
int v[11111];
int vcomp(const void *a, const void *b) {
	double d = as[*(int*)a] - as[*(int*)b];
	return (d < 0) - (d > 0);
}
int main() {
	int z, n;
	sf("%d", &z);
	fq(cas,z) {
		sf("%d", &n);
		fr(i,n<<1) sf("%lf", as + i), v[i] = i;
		qsort(v, n<<1, sizeof(int), vcomp);
		sort(as, as + n), sort(as + n, as + (n<<1));
		int b = 0, a = 0, d = 0, p = n;
		fr(i,n) while (p < (n<<1) && as[i] > as[p++]) b++;
		fr(i,n<<1) if (v[i] < n) d++; else if (a > --d) a = d;
		pf("Case #%d: %d %d\n", cas, a+n, b);
	}	
}
