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


#include<set>
#include<map>
#include<vector>
using namespace std;

int r, n, m, k;
ll fac[111];
ll vals[51111];
double freq[51111];
map<int,map<int,int>*> fqs;
int valc = 0;
map<ll,int> ps;
ll psk[51111];
int psc = 0;
double maxp[51111];

int ct[1111];
double prods(int c, ll pd, ll kt, map<int,int> *mp) {
	if (c > m) {
		if (ps.find(pd) == ps.end()) {
			pf("bad prod: %lld\n", pd);
		}
		int w = ps[pd];
		if (mp -> find(w) == mp ->end()) {
			(*mp)[w] = (int)kt;
		} else {
			(*mp)[w] += (int)kt;
		}
		return pd;
	} else {
		ll pw = 1;
		double aa = 0;
		for (int t = 0; t <= ct[c]; t++) {
			double a2 = prods(c + 1, pd * pw, kt * fac[ct[c]] / fac[t] / fac[ct[c] - t], mp);
			if (aa < a2) aa = a2;
			pw *= c;
		}
		return aa;
	}
}
/*void prods(ll t, ll pd, map<int,int> *m) {
	if (!t) {
		int w = ps[pd];
		if (m -> find(w) == m ->end()) {
			(*m)[w] = 1;
		} else {
			(*m)[w]++;
		}
	} else {
		prods(t / 10, pd, m);
		prods(t / 10, pd * (t % 10), m);
	}
}*/
void enumr(int i, int x, int ct, ll denom, ll pd, ll t) {
	if (ps.find(pd) == ps.end()) {
		psk[psc] = pd;
		ps[pd] = psc++;
	}
	if (i == n) {
		denom *= fac[ct];
		freq[valc] = fac[n] / denom;
		vals[valc] = t;
		fqs[valc] = new map<int,int>;
		valc++;
	} else {
		enumr(i + 1, x, ct + 1, denom, pd * x, t * 10 + x);
		for (int j = x + 1; j <= m; j++) {
			enumr(i + 1, j, 1, denom * fac[ct], pd * j, t * 10 + j);
		}
	}
}
int main() {
	*fac = 1;
	for (int i = 1; i < 111; i++) {
		fac[i] = i * fac[i - 1];
	}
	int z;
	sf("%d", &z);
	pf("Case #1:\n");
	sf("%d%d%d%d", &r, &n, &m, &k);
//	pf("k is %d\n", k);

	enumr(0, 2, 0, 1, 1, 0);
	fr(i,valc) {
//		if (!(i & 127))
//		pf("%d %d\n", i, valc);
		fr(j,m+1) ct[j] = 0;
		for (ll w = vals[i]; w; w /= 10) {
			ct[w % 10]++;
		}
		double base = prods(2, 1, 1, fqs[i]);
		maxp[i] = 1;
		fr(j,k) maxp[i] *= base;
		/*
		map<int,int>::iterator iter;
		pf("====\n");
		pf("%d: %lld %.1lf\n", i, vals[i], freq[i]);
		for (iter = fqs[i] ->begin(); iter != fqs[i]->end(); iter++) {
			pf("%d (%lld) has %d\n", iter -> first, psk[iter -> first], iter -> second);
		}*/
	}
/*	fr(i,valc) {
		pf("%d: %lld %.1lf\n", i, vals[i], freq[i]);
	}
	pf("%d\n", valc);*/

//	fr(i,psc) {
//		pf("%d: %lld\n", i, psk[i]);
//	}
//	pf("%d...\n", psc);
//	pf("k is %d\n", k);
	int w[k];
	double mn = 1e111;
	fr(i,r) {
//		if (!(i & 127))
//		pf("%d %d\n", i, r);
		fr(j,k) {
			ll val;
			sf("%lld", &val);
			w[j] = ps[val];
			if (ps.find(val) == ps.end()) {
				pf("bad %lld\n", val);
			}
		}
		int best = 0;
		double prob = -1;
		fr(sol,valc) {
			double fw = freq[sol];
			if (fw * maxp[sol] < prob) continue;
			map<int,int> *mp = fqs[sol];
			fr(ku,k) {
				int ww = w[ku];
//				pf("(%lld)\n", psk[ww]);
				if (mp -> find(ww) == mp -> end()) {
					fw = 0;
					break;
				}
				fw *= (*mp)[ww];
			}
//			pf("%d %lld %.2lf\n", sol, vals[sol], fw);
			if (prob < fw) {
				best = sol;
				prob = fw;
				//if (prob >= 61312204800000000.00000) break;
//				if (prob >= 1704430243676160000.00000) break;
			}
		}
		if (prob < 0) {
			pf("BADDDD\n");
		}
		if (mn > prob) mn = prob;
		//pf("%lld %.5lf\n", vals[best], mn);
		pf("%lld\n", vals[best]);
	}

}
