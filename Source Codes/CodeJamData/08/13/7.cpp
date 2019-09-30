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

int nc2(int n)
{
  int a=n;
  int b=n-1;
  if(a%2==0) a/=2; else b/=2;
  a%=1000;
  b%=1000;
  return (a*b)%1000;
}
int nc4(int n)
{
  int a[4];
  REP(i,4) a[i]=n-i;
  REP(j,3) { REP(i,4) if(a[i]%2==0) { a[i]/=2; break; } }
             REP(i,4) if(a[i]%3==0) { a[i]/=3; break; }
  int r=1;
  REP(i,4) a[i]%=1000;
  REP(i,4) r=(r*a[i])%1000;
  return r;
}
int pow3(int n)
{
  if(n==0) return 1;
  if(n==1) return 3;
  if(n%2) return (3*pow3(n-1))%1000;
  int t=pow3(n/2);
  return (t*t)%1000;
}

void _case(int casenum)
{
  int n;
  scanf("%d",&n);
  int mod8=0;
  if(n==2) mod8=4;
  int mod125=0;
  mod125+=2*pow3(n);
  mod125%=125;
  mod125+=2*pow3(n-2)*5*nc2(n);
  mod125%=125;
  if(n>=4)
  {
    mod125+=((2*pow3(n-4)*25)%125)*nc4(n);
    mod125%=125;
  }
  int res=mod125;
  while((res%8)!=mod8) res+=125;
  res+=999;
  res%=1000;
  printf("Case #%d: %c%c%c\n",casenum,'0'+res/100,'0'+(res/10)%10,'0'+res%10);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
