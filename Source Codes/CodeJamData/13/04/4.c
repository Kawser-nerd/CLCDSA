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
	short *dst = alok(1<<20,short);
	short *key[20];
	short ops[111];
	fr(i,20) key[i] = alok(1<<20,short);
	short pos[1111];
	short ser[1111];
	fr(i,1111) pos[i] = -1;
	#define reg(i) do {\
		if (pos[i] < cas) {\
			pos[i] = cas;\
			ser[i] = ct++;\
		}\
		i = ser[i];\
	} while (0)
	#define get(i) do {\
		if (pos[i] < cas) {\
			i = -1;\
		} else {\
			i = ser[i];\
		}\
	} while (0)
	int cur[1111];
	int chk[20];
	int cht[20][1111];
	fq(cas,z) {
		int k, n, ct = 0;
		sf("%d%d", &k, &n);
		int shn = 1 << n;
		fr(i,20) {
			fr(j,1<<20) key[i][j] = 0;
		}
		fr(i,k) {
			sf("%d", cur + i);
		}
		fr(i,n) {
			int o;
			sf("%d%d", &o, chk + i);
			reg(o);
			ops[i] = o;
			fr(j,chk[i]) {
				sf("%d", cht[i] + j);
			}
		}
		fr(i,n) {
			int shi = 1 << i;
			fr(j,chk[i]) {
				int v = cht[i][j];
				get(v);
//				pf("%d has %d\n", i, v);
				if (v >= 0) {
					key[v][shi]++;
				}
			}
//			pf("(%d):",i);
//			fr(j,ct) {
//				pf(" %d", key[j][shi]);
//			}
//			pln;
//			pf("opened by %d\n", ops[i]);
			key[ops[i]][shi]--;
//			pf("(%d):",i);
//			fr(j,ct) {
//				pf(" %d", key[j][shi]);
//			}
//			pln;
		}
//		fr(i,shn) {
//			pf("i=%d:", i);
//			fr(j,ct) {
//				pf(" %d", key[j][i]);
//			}
//			pln;
//		}
		fr(i,n) {
			int shi = 1 << i;
			fr(j,shi) {
				fr(l,ct) {
					key[l][shi | j] = key[l][shi] + key[l][j];
				}
			}
		}
		fr(i,k) {
			int v = cur[i];
			get(v);
//			pf("start has %d...%d\n", v, k);
			if (v >= 0) {
				fr(j,1<<n) {
					key[v][j]++;
				}
			}
		}
//		fr(i,shn) {
//			pf("i=%d:", i);
//			fr(j,ct) {
//				pf(" %d", key[j][i]);
//			}
//			pln;
//		}
//		fr(i,n) {
//			pf("%d open: %d\n", i, ops[i]);
//		}
		ffr(i,shn) {
//			pf("i is now %d\n", i);
			dst[i] = i == shn - 1 ? 0 : -1;
			fr(w,n) {
				int shw = 1 << w;
				int di = shw | i;
//				pf("dest %d gives %d %d and %d %d %d %d\n", w, shw, di, shw & i, key[ops[w]][i], key[ops[w]][di], dst[di]);
				if (!(shw & i) && key[ops[w]][i] > 0 && key[ops[w]][di] >= 0 && dst[di] >= 0) {
//					pf("dst is %d!\n", w);
					dst[i] = w;
					break;
				}
			}
//			pf("done %d %d\n", i, dst[i]);
		}
		pf("Case #%d:", cas);
		if (*dst >= 0) {
			int w = *dst;
			int hmp = 1<<w;
//			pf("(%d %d)\n", w, hmp);
			fr(i,n) {
//				pf("[%d %d %d]\n", i, w, hmp);
				pf(" %d", w+1);
				w = dst[hmp];
//				pf("{%d}", w);
				hmp |= 1 << w;
			}
		} else {
			pf(" IMPOSSIBLE");
		}
		pln;
	}	
}