#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
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
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void init() {

}
#define LIM 11111
int s[LIM];
ll flr(ll,ll);
ll cil(ll a, ll b) {
	if (a < 0) return -flr(-a, b);
	return (a + b - 1) / b;
}
ll flr(ll a, ll b) {
	if (a < 0) return -cil(-a, b);
	return a / b;
}
ll solve() {
	int n, k;
	sf("%d%d", &n, &k);
	fr(i,n-k+1) {
		sf("%d", s + i);
	}
	// s[i] = x[i] + ... + x[i+k-1]
	// s[i+1] = x[i+1] + ... + x[i+k]
	// s[i+1] - s[i] = x[i+k] - x[i]
	ll A = 0, B = 0;
	ll bamax = 0;
	fr(i,k) {
		ll a = 0, b = 0;
		ll v = 0;
		for (int j = i+k; j < n; j += k) {
			v += s[j-k+1] - s[j-k];
			a = min(a, v);
			b = max(b, v);
		}
		bamax = max(bamax, b - a);
		// pf("%lld %lld\n", a, b);
		A += a;
		B += b;
	}
	ll L = flr(s[0] + A, k);
	ll U = max(cil(s[0] + B, k), L + bamax);
	return U - L;
}
int main() {
	init();
    int z;
    sf("%d", &z);
    fq(cas,z) {

        pf("Case #%d: %lld\n", cas, solve());
    }    
}
