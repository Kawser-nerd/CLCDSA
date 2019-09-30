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

void _case(int casenum)
{
  int n;
  scanf("%d",&n);
  long long t;
  vector<long long> x,y;
  REP(i,n) { scanf("%lld",&t); x.PB(t); }
  REP(i,n) { scanf("%lld",&t); y.PB(t); }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  t=0;
  REP(i,n) t+=x[i]*y[i];
  printf("Case #%d: %lld\n",casenum,t);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
