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

mt19937 rng;

const int NITERS = 5;
const double TIME_LIMIT = 6.0;

int N,M;
vector<vector<int>> spells;

void ReadInput() {
  cin >> N >> M;
  spells.clear();
  spells.resize(N);
  REP(i,N) {
    spells[i].resize(M);
    REP(j,M) cin >> spells[i][j];
  }
}

int CalcProfit(const vector<int> &order) {
  static vector<int> cur;
  cur.assign(M, 0);
  for(const int o : order) {
    const vector<int> &spell = spells[o];
    REP(i,M) {
      cur[i] = max(cur[i] + spell[i], 0);
    }
  }
  int res = 0;
  REP(i,M) res += cur[i];
  return res;
}

int SimAnn() {
  double startTime = WallTime();
  double endTime = startTime + TIME_LIMIT;
  vector<int> order(N);
  REP(i,N) order[i]=i;
  shuffle(order.begin(), order.end(), rng);

  int val = CalcProfit(order);
  int bestVal = val;
  double temp0 = 1e4;
  double temp1 = 1e-4;
  bool neighbors=false;
  for(;;) {
    double curTime = WallTime();
    if(curTime>=endTime) break;
    double frac = (curTime-startTime)/(endTime-startTime);
    double temp = exp(log(temp0)*(1-frac) + log(temp1)*frac);
    
    int a,b;
    if(neighbors) {
      a = uniform_int_distribution<int>(0, N-2)(rng);
      b = a+1;
    } else {
      a = uniform_int_distribution<int>(0, N-1)(rng);
      b = uniform_int_distribution<int>(0, N-2)(rng);
      if(b>=a) ++b;
    }
    swap(order[a], order[b]);
    int newVal = CalcProfit(order);
    if(newVal >= val || bernoulli_distribution(exp((newVal-val)/temp))(rng)) {
      val = newVal;
      if(val>bestVal) bestVal=val;
    } else {
      swap(order[a], order[b]);
    }
    neighbors = !neighbors;
  }
  return bestVal;
}

int Calc() {
  if(N==1) {
    vector<int> order(1,0);
    return CalcProfit(order);
  }
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

