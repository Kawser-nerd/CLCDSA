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
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

class TestCase {
 public:
  static const int h = 1011;
  int n;
  double a[h], b[h];

  void input() {
    scanf("%d", &n);
    REP(i, n) scanf("%lf", a+i);
    REP(i, n) scanf("%lf", b+i);
  }

  void solve() {
    sort(a, a+n);
    sort(b, b+n);
    int f = 0, d = 0;
    int x = 0, y = n - 1;
    FORD(i, n-1, 0) {
      if (a[i] > b[y]) {
        ++f;
        ++x;
      } else {
        --y;
      }
    }
    x = 0;
    y = n - 1;
    REP(i, n) {
      if (a[i] > b[x]) {
        ++d;
        ++x;
      } else {
        --y;
      }
    }
    outp("%d %d", d, f);
  }

  string out;
 private:
  static const int L = 1024;
  char buf[L+1];

  void outp(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, L, fmt, args);
    va_end(args);
    out.append(buf);
  }
};

mutex io_mutex;
int itest, ntest;
vector<string> answer;

void work() {
  while (true) {
    io_mutex.lock();
    if (itest >= ntest) {
      io_mutex.unlock();
      break;
    }
    int wtest = itest;
    ++itest;
    cerr << "Case " << wtest+1 << " started\n";
    TestCase test;
    test.input();
    io_mutex.unlock();
    test.solve();
    answer[wtest].swap(test.out);
  }
}

int main() {
  freopen("d-large.in", "r", stdin);  // -small-attempt0
  freopen("d-large.out", "w", stdout);  // -large
  itest = 0;
  scanf("%d", &ntest);
  answer.resize(ntest);
#ifdef MULTITHREADING
  vector<thread> threads;
  REP (i, thread::hardware_concurrency()) threads.pb(thread(work));
  REP (i, sz(threads)) threads[i].join();
  REP (i, ntest) printf("Case #%d: %s\n", i + 1, answer[i].c_str());
#else
  REP (i, ntest) {
    cerr << "Case " << i+1 << " started\n";
    TestCase test;
    test.input();
    test.solve();
    printf("Case #%d: %s\n", i + 1, test.out.c_str());
  }
#endif
  cerr << endl << endl << "TIME: " << clock() << endl;
  return 0;
}
