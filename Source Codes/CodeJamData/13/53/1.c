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


#define INF 111111111111111111LL
#include<queue>
using namespace std;

int main() {
	int z;
	sf("%d", &z);
  int *as = alok(11111, int);
  int *bs = alok(11111, int);
  ll *cs = alok(11111, ll);
  ll *ds = alok(11111, ll);
  ll *es = alok(11111, ll);
  ll *dst = alok(11111, ll);
  int **adj = alok(1111, int*);
  int **jda = alok(1111, int*);
  int **jdi = alok(1111, int*);
  int *cda = alok(1111, int);
  ll **wda = alok(1111, ll*);
  ll **adw = alok(1111, ll*);
  int *adc = alok(1111, int);
  fr(i,1111) {
    adj[i] = alok(1111, int);
    adw[i] = alok(1111, ll);
    jda[i] = alok(1111, int);
    wda[i] = alok(1111, ll);
    jdi[i] = alok(1111, int);
  }
  int *hs = alok(11111, int);
  int *gud = alok(1111, int);
  int *stk = alok(1111, int);
  int *vis = alok(1111, int);
  int *ovis = alok(11111, int);
  priority_queue<ll> que;
	fq(cas,z) {
		pf("Case #%d: ", cas);
    int n, m, p;
    sf("%d%d%d", &n, &m, &p);
    fr(i,m) {
      sf("%d%d%lld%lld", as + i, bs + i, cs + i, ds + i);
      as[i]--;
      bs[i]--;
      es[i] = ds[i];
    }
    fr(i,p) {
      int h;
      sf("%d", &h);
      hs[i] = --h;
    }
    fr(i,m) ovis[i] = 0;
    int bad = -1;
    fr(mm,1<<m) {
      //pf("at %d\n", mm);
      fr(i,n) {
        adc[i] = 0;
        cda[i] = 0;
        vis[i] = 0;
      }
      fr(i,m) es[i] = ((mm&(1<<i))?ds[i]:cs[i]);
      fr(i,m) {
        int a = as[i];
        int b = bs[i];
        ll d = es[i];
        adj[a][adc[a]] = b;
        adw[a][adc[a]++] = d;
        jda[b][cda[b]] = a;
        wda[b][cda[b]] = d;
        jdi[b][cda[b]++] = i;
      }
      que.push(0);
      fr(i,n) dst[i] = INF;
      while (!que.empty()) {
        ll hsh = -que.top();
        que.pop();
        int i = hsh % (n+1);
        if (dst[i] < INF) continue;
        ll c = hsh / (n+1);
        dst[i] = c;
        fr(nb,adc[i]) {
          int ij = adj[i][nb];
          ll ic = adw[i][nb];
          if (dst[ij] >= INF) {
            ll nc = c + ic;
            ll nhsh = nc * (n+1) + ij;
            que.push(-nhsh);
          }
        }
      }
/*      pf("[%d]\n", mm);
      fr(i,n) {
        pf("(%d %lld)\n", i, dst[i]);
      }
*/      // dfs
      stk[0] = 1;
      vis[1] = 1;
      int stc = 1;
      while (stc) {
        int j = stk[--stc];
        fr(nb,cda[j]) {
          int i = jda[j][nb];
          if (wda[j][nb] + dst[i] == dst[j]) {
            ovis[jdi[j][nb]] = 1;
            if (!vis[i]) {
              vis[i] = 1;
              stk[stc++] = i;
            }
          }
        }
      }
      /*fe(i,0,sus) {
        int di = hs[i];
        if (dst[bs[di]] != dst[as[di]] + ds[di]) {
          bad = hs[sus];
          break;
        }
      }*/
    }
    fr(i,p) {
      int h = hs[i];
      if (!ovis[h]) {
        bad = h;
        break;
      }
    }
    if (~bad) {
      pf("%d", bad + 1);
    } else {
      pf("Looks Good To Me");

    }
		pln;
	}
}