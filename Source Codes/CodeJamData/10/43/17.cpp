#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(__typeof(a)i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a)i=(a);i>=(b);--i)
#define REP(i,n) for(__typeof(n)i=0;i<(n);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

vector<string> split(const string& s, const string& delim=" ")
{ vector<string> res; string t; for(unsigned int i=0;i<s.length();i++) { if(delim.find(s[i])!=string::npos) { if(!t.empty()) { res.PB(t); t=""; } } else t+=s[i]; } if(!t.empty()) res.PB(t); return res; }
vector<int> splitint(const string& s, const string& delim=" ") { vector<string> vs=split(s); vector<int> res; for(unsigned int i=0;i<vs.size();i++) res.PB(atoi(vs[i].c_str())); return res; }

int x[1000],y[1000],xx[1000],yy[1000];
vector<int> a[1000];

bool touch(int a, int b)
{
  if(x[a]>xx[b]+1) return false;
  if(x[b]>xx[a]+1) return false;
  if(y[a]>yy[b]+1) return false;
  if(y[b]>yy[a]+1) return false;
  if((x[a]==xx[b]+1)&&(y[a]==yy[b]+1)) return false;
  if((x[b]==xx[a]+1)&&(y[b]==yy[a]+1)) return false;
  return true;
}

bool b[1000];
int c[1000];

void dfs(int x)
{
  REP(i,(int)a[x].size()) if(!b[a[x][i]]) { b[a[x][i]]=true; c[a[x][i]]=c[x]; dfs(a[x][i]); }
}

void _case(int casenum)
{
  int r; scanf("%d",&r);
  REP(i,r) scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
  REP(i,r) a[i].clear();
  REP(i,r)REP(j,r) if(touch(i,j)) { a[i].PB(j); a[j].PB(i); }

  int res=0;

  REP(i,r) b[i]=false;
  REP(i,r) c[i]=-1;
  REP(i,r)
    if(!b[i])
    {
      b[i]=true; c[i]=i; dfs(i);

      int ms=x[i]+y[i];
      int mx=xx[i];
      int my=yy[i];
      REP(j,r) if(c[j]==i) { ms=min(ms,x[j]+y[j]); mx=max(mx,xx[j]); my=max(my,yy[j]); }

      res=max(res,1+mx+my-ms);
    }

  printf("Case #%d: %d\n",casenum,res);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
