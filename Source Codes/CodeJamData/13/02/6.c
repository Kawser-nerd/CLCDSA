#include<stdio.h>
#include<stdlib.h>
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

int main() {
	int z;
	sf("%d", &z);
	int _gr[111][111];
	#define gr(i,j) _gr[i][j]
	#define rg(i,j) _gr[j][i]
	int _vs[111][111];
	#define vs(i,j) _vs[i][j]
	#define sv(i,j) _vs[j][i]
	fq(cas,z) {
		int r, c;
		sf("%d%d", &r, &c);
		fr(i,r) {
			fr(j,c) {
				sf("%d", &_gr[i][j]);
				_vs[i][j] = 0;
			}
		}
	#define foo(r,c,gr,vs) do {\
		fr(i,r) {\
			int mx = -1;\
			fr(j,c) {\
				if (mx < gr(i,j)) mx = gr(i,j);\
			}\
			fr(j,c) {\
				vs(i,j) |= gr(i,j) == mx;\
			}\
		}\
	} while (0)
		foo(r,c,gr,vs);
		foo(c,r,rg,sv);
		int succ = 1;
		fr(i,r) {
			fr(j,c) {
				if (!_vs[i][j]) {
					succ = 0;
					break;
				}
			}
			if (!succ) break;
		}
		pf("Case #%d: %s\n", cas, succ ? "YES" : "NO");
	}	
}