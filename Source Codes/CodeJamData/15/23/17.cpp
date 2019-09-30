#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <thread>
#include <mutex>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T gcd(T a, T b) {
  if (a < 0) a = -a; if (b < 0) b = -b;
  while (a && b) { if (a >= b) a %= b; else b %= a; } return a + b; }
template<class T> T sqr(const T& a) { return a * a; }


class TestCase {
 public:
  // data
  static const int N = 500001;
  int n;
  int d[N], m[N];

  TestCase() {  // input
    scanf("%d", &n);
    int u = 0;
    REP(i, n) {
      int h;
      scanf("%d%d%d", d+u, &h, m+u);
      FOR(i, 1, h) {
        d[u+i] = d[u];
        m[u+i] = m[u] + i;
      }
      u += h;
    }
    n = u;
  }

  void solve() {
    //printf("%d\n", n);
    //REP(i, n) printf("%d, %d\n", d[i], m[i]);
    REP(i, n) d[i] = 360 - d[i];
    typedef pair<ll, int> pli;
    vector<ll> e(n);
    priority_queue<pli> q;
    REP(i, n) {
      e[i] = ll(m[i]) * d[i];
      q.push(pli(-ll(m[i]) * (d[i] + 360), i));
      //printf("%d: %I64d %I64d\n", i, e[i], ll(m[i]) * (d[i] + 360));
    }
    sort(all(e));
    int ans = n;
    int cur0 = n, cur1 = 0;
    REP(i, n) {
      while (-q.top().X <= e[i]) {
        ++cur1;
        if (cur1 >= n) break;
        pli t = q.top();
        q.pop();
        t.X -= ll(m[t.Y]) * 360;
        q.push(t);
      }
      --cur0;
      //printf("%d: %I64d, (%d,%d)\n", i, e[i], cur0, cur1);
      smin(ans, cur0 + cur1);
      if (cur1 >= n) break;
    }
    print("%d", ans);
  }

  string out;
 private:
  static const int __L = 1024;
  char buf[__L+1];

  void print(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, __L, fmt, args);
    va_end(args);
    out.append(buf);
  }

  template<typename Iterator>
  void printi(const char* fmt, Iterator begin, Iterator end,
      const char* separator = " ") {
    for (Iterator it = begin; it != end; ++it) {
      if (it != begin) print(separator);
      print(fmt, *it);
    }
    print("\n");
  }
};

mutex input_mutex;
int itest, ntest;
vector<string> answer;

void work() {
  while (true) {
    input_mutex.lock();
    if (itest >= ntest) {
      input_mutex.unlock();
      break;
    }
    int wtest = itest++;
    cerr << "Case " << wtest + 1 << " started\n";
    TestCase* test = new TestCase();
    input_mutex.unlock();
    test->solve();
    answer[wtest].swap(test->out);
    delete test;
  }
}

void output(int test, const string& ans) {
  printf("Case #%d: %s\n", test + 1, ans.c_str());
}

int main() {
  freopen("c-large.in", "r", stdin);  // -small-attempt0
  freopen("c-large.txt", "w", stdout);  // -large
  itest = 0;
  scanf("%d", &ntest);
  answer.resize(ntest);
#ifdef MULTITHREADING
  vector<thread> threads;
  REP(i, thread::hardware_concurrency()) threads.pb(thread(work));
  REP(i, sz(threads)) threads[i].join();
  REP(i, ntest) output(i, answer[i]);
#else
  REP(i, ntest) {
    cerr << "Case " << i + 1 << " started\n";
    TestCase* test = new TestCase();
    test->solve();
    output(i, test->out);
    delete test;
  }
#endif
  cerr << endl << endl << "TIME: " << clock() << endl;
  return 0;
}
