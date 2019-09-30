#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<ll> > vvll;
typedef std::deque<bool> db;
template<class T> using vv=std::vector<std::vector< T > >;

// cout vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<std::deque<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout set<cout-able>
template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& v) {
  s<<"\n";for(auto elm : v){s<<elm<<"\t";}s<<"\n";return s; }

inline void scan(int&a){scanf("%d",&a);}
inline void scan(int&a,int&b){scanf("%d%d",&a,&b);}
inline void scan(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void scan(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void scan(std::vector<int>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<int> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(ll&a){scanf("%lld",&a);}
inline void scan(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void scan(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void scan(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void scan(std::vector<ll>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<ll> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(char&a){scanf(" %c",&a);}
inline void scan(std::vector<char>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<char> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}

inline void print(int a){printf("%d\n",a);}
inline void print(int a,int b){printf("%d %d\n",a,b);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(ll a,ll b){printf("%lld %lld\n",a,b);}
inline void print(std::string s){std::cout << s << "\n";}
inline void print_yn(bool flg){if(flg){printf("Yes\n");}else{printf("No\n");}}

using namespace std;

struct edge { int to, rev; ll cap; };
vv<edge> g;
vi itr, level;

void add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, int(g[to].size()), cap});
  g[to].push_back((edge){from, int(g[from].size()-1), 0});
}

int n, m; // number of nodes, edges
vector<bool> used;
ll INF = 1e18;

void debug_g() {
  rep (i, n) {
    printf("u : %d\n", i);
    for (auto e : g[i]) {
      printf("%d %lld, ", e.to, e.cap);
    }
    printf("\n");
  }
}

void dinic_bfs(int s) {
  level.assign(n, -1);
  deque<int> q;
  level[s] = 0;
  q.push_back(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (edge& e : g[v]) {
      if (e.cap > 0 and level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        q.push_back(e.to);
      }
    }
  }
}

ll dinic_dfs(int v, int t, ll f) {
  if (v == t) {
    return f;
  }
  int sz = g[v].size();
  FOR (i, itr[v], sz) {
    edge& e = g[v][i];
    if (level[v] >= level[e.to] or e.cap <= 0) { continue; }
    ll d = dinic_dfs(e.to, t, min(f, e.cap));
    if (d > 0) {
      e.cap -= d;
      g[e.to][e.rev].cap += d;
      return d;
    }
  }
  return 0;
}

ll dinic(int s, int t) {
  ll flow = 0;
  ll f;
  while (dinic_bfs(s), level[t] >= 0) {
    itr.assign(n, 0);
    while (true) {
      f = dinic_dfs(s, t, INF);
      if (f > 0) {
        flow += f;
      } else {
        break;
      }
    }
  }
  return flow;
}

int main() {
  int nn;
  scan(nn);
  vi a(nn);
  scan(a);
  map<int, int> cnt;
  rep (i, nn) {
    cnt[a[i]] += 1;
  }

  vi id2num;
  vi id2cnt;
  for (auto p : cnt) {
    id2num.push_back(p.first);
    id2cnt.push_back(p.second);
  }
  int n = id2num.size();

  vi beki(31, 1);
  rep (i, 30) {
    beki[i+1] = beki[i] * 2;
  }
  vi used_cnt(n, 0);

  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (used_cnt[i] == id2cnt[i]) { continue; }
    int target_beki = *(upper_bound(all(beki), id2num[i]));
    int target = target_beki - id2num[i];
    debug2(id2num[i], target);
    auto ub = upper_bound(begin(id2num), begin(id2num) + i + 1, target);
    auto lb = lower_bound(begin(id2num), begin(id2num) + i + 1, target);
    if (ub == lb) { continue; }
    int ind = lb - begin(id2num);
    if (used_cnt[ind] == id2cnt[ind]) { continue; }

    if (i == ind) {
      int rest = id2cnt[i] - used_cnt[i];
      ans += rest/2;
    } else {
      int rest1 = id2cnt[i] - used_cnt[i];
      int rest2 = id2cnt[ind] - used_cnt[ind];
      int add = min(rest1, rest2);
      ans += add;
      used_cnt[i] += add;
      used_cnt[ind] += add;
    }
  }
  print(ans);
  return 0;
}