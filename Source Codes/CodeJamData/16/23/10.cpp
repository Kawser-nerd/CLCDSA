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

template <int V1, int V2>
class Matching {
  int dist[V1], queue[V1];

  template <class G>
  bool bfs(const G& graph) {
    int* tail = queue;
    for (int i = 0; i < graph.size(); ++i)
      if (match1[i] == -1) dist[*tail++ = i] = 1;
      else dist[i] = -1;
    for (int* v = queue; v != tail; ++v)
      for (int u : graph[*v]) {
        int mu = match2[u];
        if (mu == -1) return true;
        if (dist[mu] == -1) dist[*tail++ = mu] = dist[*v] + 1;
      }
    return false;
  }

  template <class G>
  bool dfs(const G& graph, int v) {
    for (auto u = graph[v].begin() + queue[v]; u != graph[v].end();
         ++u, queue[v] = graph[v].end() - u) {
      int& mu = match2[*u];
      if (mu == -1 || (dist[mu] == dist[v] + 1 && dfs(graph, mu))) {
        match1[v] = *u;
        mu = v;
        return true;
      }
    }
    return false;
  }

public:
  int match1[V1], match2[V2];

  template <class G>
  int maxMatching(const G& graph) {
    int n = graph.size();
    fill_n(match1, n, -1);
    fill_n(match2, graph.size2(), -1);
    while (bfs(graph)) {
      fill_n(queue, n, 0);
      for (int i = 0; i < n; ++i) if (match1[i] == -1) dfs(graph, i);
    }
    return n - static_cast<int>(count(match1, match1 + n, -1));
  }
};

template <int V, bool ORIENTED = false>
class GraphUL {
  int n, m;
  vector<int> adjacent[V];

public:
  GraphUL(int newn = 0, int newm = -1) : n(0) { init(newn, newm); }

  void init(int newn, int newm = -1) {
    for (int i = 0; i < n; ++i) vector<int>().swap(adjacent[i]);
    n = newn;
    m = newm >= 0 ? newm : n;
  }

  void addEdge(int u, int v) {
    assert(u < n && v < m);
    adjacent[u].push_back(v);
    if (!ORIENTED && u != v) adjacent[v].push_back(u);
  }

  bool oriented() const { return ORIENTED; }
  int size() const { return n; }
  int size2() const { return m; }
  const vector<int>& operator [] (int v) const { return adjacent[v]; }
};


class TestCase {
public:
  // data
  static const int N = 1111, L = 22;
  int n;
  char s[N][2][L];
  map<string, int> m[2];

  void input() {
    scanf("%d", &n);
    REP(i, n) REP(j, 2) scanf("%s", s[i][j]);
  }

  void generate(bool big, int seed) {
    auto rnd = bind(uniform_int_distribution<int>(0, 9),
                    default_random_engine(seed));
  }

  void solveSlow() {
  }

  int index(int u, string x) {
    if (m[u].count(x)) return m[u][x];
    else return m[u][x] = sz(m[u]);
  }

  void solve() {
    GraphUL<N, true> graph;
    Matching<N, N> match;
    graph.init(n, n);
    REP(i, n) {
      int i0 = index(0, s[i][0]);
      int i1 = index(1, s[i][1]);
      graph.addEdge(i0, i1);
    }
    print("%d", n - sz(m[0]) - sz(m[1]) + match.maxMatching(graph));
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
  freopen("c-large.in", "r", stdin);  // -small-attempt0
  freopen("c-large.txt", "w", stdout);  // -large
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
