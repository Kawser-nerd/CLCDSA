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
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

vector<string> split(const string& s, const string& delim=" ")
{ vector<string> res; string t; for(unsigned int i=0;i<s.length();i++) { if(delim.find(s[i])!=string::npos) { if(!t.empty()) { res.PB(t); t=""; } } else t+=s[i]; } if(!t.empty()) res.PB(t); return res; }
vector<int> splitint(const string& s, const string& delim=" ") { vector<string> vs=split(s); vector<int> res; for(unsigned int i=0;i<vs.size();i++) res.PB(atoi(vs[i].c_str())); return res; }

int pun[2002];
int mal[2002];
vector<int> by[2002];

int res[2002];
bool poss;

void _case(int casenum)
{
  int n,m;
  scanf("%d%d",&n,&m);
  REP(i,n) { by[i].clear(); res[i]=0; }
  poss=true;
  queue<int> q;
  REP(i,m)
  {
    int t,x,y;
    scanf("%d",&t);
    mal[i]=-1;
    pun[i]=0;
    REP(j,t)
    {
      scanf("%d%d",&x,&y);
      x--;
      if(y) mal[i]=x; else { by[x].PB(i); pun[i]++; }
    }
    if(pun[i]==0) q.push(i);
  }
  while(!q.empty())
  {
    int nx,ac=q.front();
    q.pop();
    if(mal[ac]==-1) { poss=false; break; }
    res[mal[ac]]=1;
    REP(i,by[mal[ac]].size())
    {
      nx=by[mal[ac]][i];
      pun[nx]--;
      if(pun[nx]==0) q.push(nx);
    }
  }
  printf("Case #%d:",casenum);
  if(poss) REP(i,n) printf(" %d",res[i]);
  else printf(" IMPOSSIBLE");
  printf("\n");
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
