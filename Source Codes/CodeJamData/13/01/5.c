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
	char *s = alok(10,char);
	int wins[10] = {
		0xf000,
		0x0f00,
		0x00f0,
		0x000f,
		0x8888,
		0x4444,
		0x2222,
		0x1111,
		0x8421,
		0x1248,
	};
	fq(cas,z) {
		int mx = 0;
		int mo = 0;
		int ma = 0;
		fr(i,4) {
			sf("%s", s);
			fr(j,4) {
				mx <<= 1;
				mo <<= 1;
				ma <<= 1;
				if (s[j] == 'X' || s[j] == 'T') mx |= 1;
				if (s[j] == 'O' || s[j] == 'T') mo |= 1;
				if (s[j] != '.') ma |= 1;
			}
		}
		int wo = 0;
		int wx = 0;
		fr(i,10) {
			wo |= (mo & wins[i]) == wins[i];
			wx |= (mx & wins[i]) == wins[i];
		}
		pf("Case #%d: ", cas);
		if (wo) {
			pf("O won");
		} else
		if (wx) {
			pf("X won");
		} else
		if (ma == (1<<16)-1) {
			pf("Draw");
		} else
			pf("Game has not completed");
		pln;
	}	
}