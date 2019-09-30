#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define fprintf(...)
typedef long double ld;

int cas=0;
int n;
int nocc[30];
int xs[1000],ys[1000];
vector<pair<int,int> > all;
int col[30];
bool isarb[1000];
int best;
int usedn[3];
void rec(int i) {
  if (i==n) {
    int ans = 0;
    FOR(k,3) if (usedn[k]) ++ans;
    fprintf(stderr," ans = %d\n",ans);
    ans = max(ans,2);
    best = min(best,ans);
  } else {
    fprintf(stderr, "  %d: (%d, %d)\n", i, all[i].A, all[i].B);
    if (isarb[i]) rec(i+1);
    else {
      bool cando[3]={};
      FOR(k,3) cando[k] = 1;
      int y1 = max(0,all[i].B-1), y2 = min(30,all[i].B+2);
      FR(y,y1,y2) if (col[y]!=-1) {
	fprintf(stderr,"   %% %d\n",col[y]);
	cando[col[y]] = 0;
      }

      int ndo = 0;
      FOR(k,3) ndo += cando[k];
      fprintf(stderr, "    ndo = %d\n",ndo);
      FOR(k,3) fprintf(stderr, "     cando[%d] = %d\n",k,(int)cando[k]);

      if (ndo==0) return;

      int y = all[i].B;
      FOR(k,3) if (cando[k]) {
	int oldcol = col[y];
	col[y] = k;
	fprintf(stderr,"      colour %d\n",k);
	++usedn[k];
	rec(i+1);
	--usedn[k];
	col[y] = oldcol;
      }
    }
  }
}
void doit() {
  scanf("%d",&n);
  CLR(nocc,0);
  all.clear();
  FOR(i,n) {
    scanf("%d%d",&xs[i],&ys[i]);
    --xs[i];--ys[i];
    ++nocc[ys[i]];
    all.PB(MP(xs[i],ys[i]));
  }
  sort(BEND(all));
  reverse(BEND(all));
  printf("Case #%d: ",++cas);

  bool cando1 = 1;
  FOR(y,30) {
    if (nocc[y]) {
      if (nocc[y]>1) cando1 = 0;
      if ((y>0 && nocc[y-1]) || (y+1<30 && nocc[y+1])) cando1 = 0;
    }
  }

  if (cando1) {
    printf("1\n");
    return;
  }

  FOR(i,n) isarb[i] = 1;
  FOR(i,n) FOR(j,n) {
    if (all[i].B-1 == all[j].B) isarb[i] = 0;
    if (all[i].B+1 == all[j].B) isarb[i] = 0;
    if (all[i].B == all[j].B && all[i].A > all[j].A) break;
  }

  CLR(col,-1);
  best = 4;
  CLR(usedn,0);
  rec(0);

  printf("%d\n",best);
}

int zzzz;
int main() {
  scanf("%d ",&zzzz);
  FOR(i,zzzz) doit();
}
