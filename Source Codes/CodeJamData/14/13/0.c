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

#define LIM 1011
double **p;
double **pp;
int val[LIM];
int pos[LIM];
double pG = 0;
void calc(int n) {
	fr(i,n) fr(j,n) {
		p[i][j] = i == j;
	}
	ffr(k,n) {
		double **t = p; p = pp; pp = t;
		fr(i,n) fr(j,n) {
			p[i][j] = 0;
			if (i == k) {
				fr(l,n) p[i][j] += pp[l][j];
				p[i][j] /= n;
			} else {
				p[i][j] = ((n-1)*pp[i][j] + pp[k][j]) / n;
			}
		}
	}
	fr(i,n) fr(j,n) {
		p[i][j] = log(p[i][j]);
	}
	fq(i,n) {
		pG -= log(i);
	}
	/*
	fr(i,n) {
		fr(j,n) {
			pf("%.5lf ", exp(p[i][j]));
		}
		pln;
	}
	*/

}
int main() {
	p = alok(LIM, double*);
	pp = alok(LIM, double*);
	fr(i,LIM) {
		p[i] = alok(LIM, double);
		pp[i] = alok(LIM, double);
	}

	int z;
	sf("%d", &z);
	double ans[z + 1];
	double anz[z + 1];
	fq(cas,z) {
		int n;
		sf("%d", &n);
		if (cas == 1) {
			calc(n);
		}
		fr(i,n) {
			sf("%d", val + i);
		}
		double pB = 0;
		fr(i,n) {
			pB += p[val[i]][i];
		}
		ans[cas] = anz[cas] = pB;
	}
	sort(anz+1, anz + z+1);
	double thre = (anz[z + 1 >> 1] + anz[z + 2 >> 1]) * 0.5;
	fq(cas,z) {
		//pf("got f( "); fr(i,n) pf("%d ", val[i]); pf(") = %.11lf\n", exp(pB) / (exp(pB) + exp(pG)));
		pf("Case #%d: ", cas);
		if (ans[cas] >= thre) {
			pf("BAD\n");
		} else {
			pf("GOOD\n");
		}
	}
}
