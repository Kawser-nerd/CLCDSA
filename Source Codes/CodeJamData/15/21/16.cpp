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


const int P = 16;
ll d[P];

ll f(ll n) {
  ll n0 = n;
  if (n < 10) return n;
  vi a;
  while (n) {
    a.pb(n%10);
    n /= 10;
  }
  int l = sz(a), m = (l + 1) / 2;
  ll ans = d[l];
  ll x = 0, y = 0;
  FORD(i, m-1, 0) y = 10 * y + a[i];
  FOR(i, m, l) x = 10 * x + a[i];
  if (x == 1) ans += y;
  else {
    if (y == 0) {
      y = 1;
      REP(i, m) y *= 10;
      int u = m;
      while (a[u] == 0) {
        a[u] = 9;
        ++u;
      }
      --a[u];
      x = 0;
      FOR(i, m, l) x = 10 * x + a[i];
//      printf("%I64d: %I64d %I64d\n", n0, x, y);
    }
    if (x == 1) ans += y;
    else ans += y - 1 + x + 1;
  }
  return ans;
}

void calc() {
  d[1] = 1;
  ll t = 1;
  FOR(i, 2, P) {
    t *= 10;
    d[i] = f(t - 1) + 1;
  }
//  FOR(i, 1, P) printf("%d: %I64d\n", i, d[i]);
}

class TestCase {
 public:
  // data
  ll n;

  TestCase() {  // input
    scanf("%I64d", &n);
  }

  void solve() {
    print("%I64d", f(n));
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
  calc();
  freopen("a-large.in", "r", stdin);  // -small-attempt0
  freopen("a-large.txt", "w", stdout);  // -large
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
