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

#include<queue>
using namespace std;


int main() {
  int z;
  sf("%d", &z);
  int *a = alok(2111, int);
  int *b = alok(2111, int);
  int **adj = alok(2111, int*);
  fr(i,2111) {
    adj[i] = alok(6111, int);
  }
  int *deg = alok(2111, int);
  int *adc = alok(2111, int);
  int *pos = alok(2111, int);
/**/  priority_queue<int> que;
///  int *que = alok(2111, int);
  fq(cas,z) {
    pf("Case #%d:", cas);
    int n;
    sf("%d", &n);
    fr(i,n) sf("%d", a + i);
    fr(i,n) sf("%d", b + i);
    fr(i,n) {
      deg[i] = adc[i] = 0;
    }
    #define add(i,j) do {\
      deg[j]++;\
      adj[i][adc[i]++] = j;\
    } while (0)
    fo(i,1,n) {
      int added = 0;
      ffr(j,i) {
        if (!added && a[j] + 1 == a[i]) {
          added = 1;
          add(j,i);
        }
        if (a[j] >= a[i]) {
          add(i,j);
        }
      }
    }
    fr(i,n-1) {
      int added = 0;
      fo(j,i+1,n) {
        if (!added && b[i] == b[j] + 1) {
          added = 1;
          add(j,i);
        }
        if (b[j] >= b[i]) {
          add(i,j);
        }
      }
    }
/**/    fr(i,n) if (!deg[i]) que.push(-i);
///    int q = 0;
///    fr(i,n) if (!deg[i]) que[q++] = i;
    fr(f,n) {
/**/      int i = -que.top();
/**/      que.pop();
///      int i = que[f];
      fr(nb,adc[i]) {
        int j = adj[i][nb];
        if (!--deg[j]) {
/**/          que.push(-j);
///          que[q++] = j;
        }
      } 
      pos[i] = f;
    }
    fr(i,n) pf(" %d", pos[i] + 1);
    pln;
    fr(i,n) {
      int ma = 0;
      fr(j,i) {
        if (pos[j] < pos[i]) {
          if (ma < a[j]) ma = a[j];
        }
      }
      if (ma + 1 != a[i]) {
        pf("fail a %d\n", i);
      }
    }
    fr(i,n) {
      int ma = 0;
      fo(j,i+1,n) {
        if (pos[j] < pos[i]) {
          if (ma < b[j]) ma = b[j];
        }
      }
      if (ma + 1 != b[i]) {
        pf("fail b %d\n", i);
      }
    }
  }
}
