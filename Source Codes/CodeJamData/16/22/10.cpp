#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
#include <thread>
#include <mutex>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

class TestCase {
public:
  // data
  static const int N = 20;
  char a[N], b[N];

  void input() {
    scanf("%s%s", a, b);
  }

  void generate(bool big, int seed) {
    auto rnd = bind(uniform_int_distribution<int>(0, 9),
                    default_random_engine(seed));
  }

  void solveSlow() {
  }

  ll gen(const char* s, bool up = true) {
    ll v = 0;
    for (; *s; ++s) {
      v *= 10;
      if (*s == '?') v += up ? 9 : 0;
      else v += *s - '0';
    }
    return v;
  }

  ll ans = INF_LL;
  ll sa, sb;

  void greedy(int i) {
    ll va = gen(a, a[i] < b[i]);
    ll vb = gen(b, a[i] > b[i]);
    ll d = abs(va - vb);
    if (d < ans || (d == ans && (va < sa || (va == sa && vb < sb)))) {
      ans = d;
      sa = va;
      sb = vb;
    }
  }

  void solve() {
    int n = strlen(a);
    REP(i, n) {
      if (a[i] == '?') {
        if (b[i] == '?') {
          a[i] = '0';
          b[i] = '1';
          greedy(i);
          swap(a[i], b[i]);
          greedy(i);
          a[i] = b[i] = '0';
        } else {
          if (b[i] > '0') {
            a[i] = b[i] - 1;
            greedy(i);
          }
          if (b[i] < '9') {
            a[i] = b[i] + 1;
            greedy(i);
          }
          a[i] = b[i];
        }
      } else {
        if (b[i] == '?') {
          if (a[i] > '0') {
            b[i] = a[i] - 1;
            greedy(i);
          }
          if (a[i] < '9') {
            b[i] = a[i] + 1;
            greedy(i);
          }
          b[i] = a[i];
        } else {
          if (a[i] != b[i]) {
            greedy(i);
            break;
          }
        }
      }
    }
    greedy(0);
    string oa, ob;
    REP(i, n) {
      oa += sa % 10 + '0';
      sa /= 10;
      ob += sb % 10 + '0';
      sb /= 10;
    }
    reverse(all(oa));
    reverse(all(ob));
    print("%s %s", oa.c_str(), ob.c_str());
  }

  string output;
private:
  static const int __L = 1 << 9;
  char buffer[__L+1];

  void print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, __L, format, args);
    va_end(args);
    output.append(buffer);
  }

  template <typename Iterator>
  void printi(const char* format, Iterator first, Iterator last,
              const char* delimiter = " ", const char* closing = "\n") {
    for (; first != last; ++first != last ? print("%s", delimiter) : void())
      print(format, *first);
    print("%s", closing);
  }
};

mutex inputMutex;
int testIndex, testCount;
vector<string> answer;

void work() {
  while (true) {
    inputMutex.lock();
    if (testIndex >= testCount) {
      inputMutex.unlock();
      break;
    }
    int current = testIndex++;
    cerr << "Case " << current + 1 << " started\n";
    unique_ptr<TestCase> test(new TestCase());
    test->input();
    inputMutex.unlock();
    test->solve();
    answer[current].swap(test->output);
  }
}

void output(int test, const string& answer) {
  printf("Case #%d: %s\n", test + 1, answer.c_str());
}

void randomTest() {
  for (int i = 0; i < 100; ++i) {
    unique_ptr<TestCase> test(new TestCase());
    test->generate(false, i);
    test->solve();
    string output;
    output.swap(test->output);
    test->solveSlow();
    if (test->output != output) {
      cerr << "Error on test #" << i + 1 << endl;
      cerr << "Expected:\n" << test->output << endl;
      cerr << "Received:\n" << output << endl;
    }
    //cerr << output << endl;
  }
  cerr << endl << endl << "Test time: ";
  cerr << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
  exit(0);
}

void maxTest() {
  for (int i = 0; i < 100; ++i) {
    unique_ptr<TestCase> test(new TestCase());
    test->generate(true, i);
    test->solve();
    output(i, test->output);
  }
  cerr << endl << endl << "Max test time: ";
  cerr << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
  exit(0);
}

int main() {
  //randomTest();
  //maxTest();
  freopen("b-large.in", "r", stdin);  // -small-attempt0
  freopen("b-large.txt", "w", stdout);  // -large
  testIndex = 0;
  scanf("%d", &testCount);
  answer.resize(testCount);
#ifndef SINGLE_THREAD
  vector<thread> threads;
  for (int i = 0; i < thread::hardware_concurrency(); ++i)
    threads.emplace_back(work);
  for (auto& thread : threads) thread.join();
  for (int i = 0; i < testCount; ++i) output(i, answer[i]);
#else
  for (int i = 0; i < testCount; ++i) {
    cerr << "Case " << i + 1 << " started\n";
    unique_ptr<TestCase> test(new TestCase());
    test->input();
    test->solve();
    output(i, test->output);
  }
#endif
  cerr << endl << endl << "Total time: ";
  cerr << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
  return 0;
}
