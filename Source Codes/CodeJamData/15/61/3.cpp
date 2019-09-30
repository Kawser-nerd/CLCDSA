//{{{
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

vector<int> v;
vector<int> last[10];

void ReadInput() {
  string s;
  cin >> s;
  int n = size(s);
  v.resize(n);
  REP(i,n) v[i] = s[i]-'0';
}

int Calc() {
  int n = size(v);
  FOR(d,1,9) {
    last[d].resize(n+1);
    last[d][0] = -1;
    FOR(len,1,n) last[d][len] = v[len-1]==d ? len-1 : last[d][len-1];
  }
  vector<vector<int>> bestEnd;
  bestEnd.reserve(1000);
  int cost = 0;
  bestEnd.push_back(vector<int>(n+1,0));
  FOR(st,0,n) bestEnd[0][st] = st;
  while(bestEnd[cost][0]<n) {
    ++cost;
    vector<int> prev = bestEnd[cost-1];
    bestEnd.push_back(prev);
    REP(st,n) FOR(d,1,9) {
      if(d>cost) continue;      
      int p = bestEnd[cost-d][st];
      p = last[d][min(p+1, n)];
      if(p<st) continue;
      int q = bestEnd[cost-d][p+1];
      bestEnd[cost][st] = max(bestEnd[cost][st], q);
    }
  }
  return cost;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res << "\n";
  }
}

