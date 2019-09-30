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
#define INF 200100100

vector<string> split(const string& s, const string& delim=" ")
{ vector<string> res; string t; for(unsigned int i=0;i<s.length();i++) { if(delim.find(s[i])!=string::npos) { if(!t.empty()) { res.PB(t); t=""; } } else t+=s[i]; } if(!t.empty()) res.PB(t); return res; }
vector<int> splitint(const string& s, const string& delim=" ") { vector<string> vs=split(s); vector<int> res; for(unsigned int i=0;i<vs.size();i++) res.PB(atoi(vs[i].c_str())); return res; }

int p;
int m[1024];
int c[11][1024];
int b[11][1024][11];

void _case(int casenum)
{
  scanf("%d",&p);
  REP(i,(1<<p)) scanf("%d",&m[i]);
  FOR(r,1,p) REP(i,(1<<(p-r))) scanf("%d",&c[r][i]);

  FOR(k,0,p) REP(i,(1<<p)) FOR(k,0,p) b[0][i][k]=(k+m[i]>=p)?0:INF;
  FOR(r,1,p) REP(i,(1<<(p-r))) FOR(k,0,p-r)
  {
    b[r][i][k]=min(b[r-1][2*i][k]+b[r-1][2*i+1][k],c[r][i]+b[r-1][2*i][k+1]+b[r-1][2*i+1][k+1]);
    if(b[r][i][k]>INF) b[r][i][k]=INF;
  }

  printf("Case #%d: %d\n",casenum,b[p][0][0]);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
