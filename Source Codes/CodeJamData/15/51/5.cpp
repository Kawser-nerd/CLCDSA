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
int rint() { int x; cin >> x; return x; }
LL rLL() { LL x; cin >> x; return x; }
string rstring() { string x; cin >> x; return x; }

struct Node {
  int parent;
  LL salary;
  LL a,b;
  bool done;
};

int N;
LL D;
vector<Node> nodes;

vector<LL> readSequence() {
  LL s,a,c,r;
  cin >> s >> a >> c >> r;
  vector<LL> res;
  REP(i,N) {
    res.push_back(s);
    s = (s*a+c)%r;
  }
  return res;
}

void ReadInput() {
  N = rint();
  D = rint();
  vector<LL> S = readSequence();
  vector<LL> M = readSequence();
  nodes.resize(N);
  REP(i,N) {
    Node &x = nodes[i];
    x.parent = i==0 ? -1 : M[i] % i;
    x.salary = S[i];
  }
}

void ComputeRanges() {
  for(Node &x : nodes) {
    x.done=false;
    x.a = x.salary - D;
    x.b = x.salary;
  }
  nodes[0].done = true;
  vector<int> ss;
  FOR(i,1,N-1) ss.push_back(i);
  while(!ss.empty()) {
    int i = ss.back();
    Node &x = nodes[i];
    if(x.done) { ss.pop_back(); continue; }
    if(nodes[x.parent].done) {
      Node &p = nodes[x.parent];
      x.a = max(x.a, p.a);
      x.b = min(x.b, p.b);
      x.done = true;
      ss.pop_back();
    } else {
      ss.push_back(x.parent);
    }
  }
}

LL Calc() {
  ComputeRanges();
  vector<pair<int,int>> v;
  for(const Node &x : nodes) {
    if(x.a <= x.b) {
      v.push_back({x.a, 1});
      v.push_back({x.b+1, -1});
    }
  }
  sort(v.begin(), v.end());
  int res = 0;
  int sum = 0;
  for(const auto &p : v) {
    sum += p.second;
    res = max(res, sum);
  }
  return res;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res << "\n";
  }
}
