//{{{
#include <bits/stdc++.h>
#include <sys/time.h>
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

double WallTime() {
  timeval tv;
  gettimeofday(&tv, 0);
  return double(tv.tv_sec) + double(tv.tv_usec) * 1e-6;
}

const int MAXN = 100;

const int NITERS = 5;
const double TIME_LIMIT = 6.0;

int N,K;
vector<vector<int>> edges;

mt19937 rng;

void ReadInput() {
  int M;
  cin >> N >> M >> K;
  edges.clear();
  edges.resize(N);
  REP(i,M) {
    int a,b; cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

int Bfs(const vector<char> &obstructed) {
  static vector<char> vis;
  vis.assign(N,0);
  static vector<int> s0, s1, s2;
  s0.clear(); s1.clear(); s2.clear();
  s0.push_back(0);
  int dist = 0;
  while(!s0.empty() || !s1.empty()) {
    while(!s0.empty()) {
      int x = s0.back(); s0.pop_back();
      if(vis[x]) continue;
      if(x==N-1) return dist;
      vis[x]=true;
      vector<int> &next = obstructed[x] ? s2 : s1;
      for(int y : edges[x]) {
        if(!vis[y]) next.push_back(y);
      }
    }
    s0.swap(s1);
    s1.swap(s2);
    ++dist;
  }
  assert(false);
  return 0;
}

int SimAnn() {
  double startTime = WallTime();
  double endTime = startTime + TIME_LIMIT;
  vector<int> order(N);
  REP(i,N) order[i]=i;
  shuffle(order.begin()+1, order.end()-1, rng);
  vector<char> obstructed(N, 0);
  REP(i,K) obstructed[order[i]]=1;
  int dist = Bfs(obstructed);
  if(K<=1 || K>=N-1) return dist;
  int bestDist = dist;
  double temp0 = 100.0;
  double temp1 = 1e-4;
  for(;;) {
    double curTime = WallTime();
    if(curTime>=endTime) break;
    double frac = (curTime-startTime)/(endTime-startTime);
    double temp = exp(log(temp0)*(1-frac) + log(temp1)*frac);
    
    int a = uniform_int_distribution<int>(1, K-1)(rng);
    int b = uniform_int_distribution<int>(K, N-2)(rng);
    swap(order[a], order[b]);
    obstructed[order[a]]=1;
    obstructed[order[b]]=0;
    int newDist = Bfs(obstructed);
    if(newDist >= dist || bernoulli_distribution(exp((newDist-dist)/temp))(rng)) {
      dist = newDist;
      if(dist>bestDist) bestDist=dist;
    } else {
      swap(order[a], order[b]);
      obstructed[order[a]]=1;
      obstructed[order[b]]=0;
    }
  }
  return bestDist;
}

int Calc() {
  if(K<=1 || K>=N-1) return SimAnn();
  int res = 0;
  REP(iter, NITERS) {
    int res1 = SimAnn();
    res = max(res, res1);
  }
  return res;
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

