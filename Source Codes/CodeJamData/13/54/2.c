#include<stdio.h>
#include<stdlib.h>
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


int main() {
	int z;
	sf("%d", &z);
  int *hi = alok(2111111, int);
  hi[0] = -1;
  fr(i,21) {
    fr(j,1<<i) {
      hi[j|(1<<i)] = i;
    }
  }
  char *s = alok(51, char);
  double *ans = alok(1111111, double);
	fq(cas,z) {
    sf("%s", s);
    int n = strlen(s);
    int m = 0;
    fr(i,n) {
      m <<= 1;
      if (s[i] == 'X') m |= 1;
    }
    ans[(1<<n)-1] = 0;
    ffo(i,m,(1<<n)-1) {
      double sum = 0;
      fr(j,n) {
        int msk = (1<<j)|((1<<j)-1);
        int vv = msk & ~i;
        if (vv) {
          int h = hi[vv];
          sum += n - (j - h) + ans[i | (1 << h)];
        } else {
          int h = hi[~i & ((1<<n)-1)];
          sum += n - (j - h + n) + ans[i | (1 << h)];
        }
      }
      ans[i] = sum / n;
    }
    pf("Case #%d: %.12lf\n", cas, ans[m]);
	}	
}