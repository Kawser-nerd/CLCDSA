#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <climits>

#ifdef _OPENMP
#include <omp.h>
#endif

using namespace std;

#define BEGIN_SOLVER struct solver {
#define END_SOLVER };

const int MAX_OUT = 10000;
const char *OUTPUT_FORMAT = "Case #%d: %s"; //"Case #%d:\n%s";

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int MAX_V = 1000010;


void init() {}



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////


struct e_t { int to, cap, rev; };

int V, S, T;
vector<e_t> adj[MAX_V];

int lev[MAX_V], done[MAX_V];

void add_edge(int i, int j, int c) {
  adj[i].push_back((e_t){j, c, (int)adj[j].size()});
  adj[j].push_back((e_t){i, 0, (int)adj[i].size() - 1});
}

bool levelize() {
  memset(lev, -1, sizeof(lev));
  queue<int> que;
  lev[S] = 0;
  que.push(S);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    rep (i, adj[v].size()) {
      e_t &e = adj[v][i];
      if (!e.cap || lev[e.to] != -1) continue;
      lev[e.to] = lev[v] + 1;
      que.push(e.to);
    }
  }
  return lev[T] != -1;
}

int augment(int v, int f) {
  if (v == T || !f) return f;
  for (; done[v] < (int)adj[v].size(); done[v]++) {
    e_t &e = adj[v][done[v]];
    if (lev[e.to] <= lev[v]) continue;
    int t = augment(e.to, min(f, e.cap));
    if (t > 0) {
      e.cap -= t;
      adj[e.to][e.rev].cap += t;
      return t;
    }
  }
  return 0;
}

int max_flow() {
  int f = 0, t;
  while (levelize()) {
    memset(done, 0, sizeof(done));
    while (t = augment(S, INT_MAX)) f += t;
  }
  return f;
}



int W, H, N;
int X0[1010], Y0[1010], X1[1010], Y1[1010];

void input() {
  scanf("%d%d%d", &W, &H, &N);
  rep (i, N) scanf("%d%d%d%d", X0 + i, Y0 + i, X1 + i, Y1 + i);
}

typedef pair<int, int> pii;
int dist(pii a, pii b) {
  if (a > b) swap(a, b);
  return max(0, b.first - a.second);
}

void solve() {
  int pot[1010];
  rep (v, N) pot[v] = X0[v];
  bool done[1010] = {};

  rep (iter, N) {
    int v = -1, p = INT_MAX;
    rep (tv, N) if (!done[tv] && pot[tv] < p) tie(v, p) = make_pair(tv, pot[tv]);
    assert(v != -1);
    done[v] = true;

    rep (w, N) {
      int d = max(dist(make_pair(X0[v], X1[v] + 1), make_pair(X0[w], X1[w] + 1)),
                  dist(make_pair(Y0[v], Y1[v] + 1), make_pair(Y0[w], Y1[w] + 1)));
      // debug("%d -> %d: %d\n", v, w, d);
      pot[w] = min(pot[w], p + d);
    }
  }
  // rep (v, N) debug("%d: %d\n", v, pot[v]);

  int ans = W;
  rep (v, N) ans = min(ans, pot[v] + (W - (X1[v] + 1)));
  printf("%d\n", ans);
}










////////////////////////////////////////////////////////////////////////////////////////////////////
// Template
////////////////////////////////////////////////////////////////////////////////////////////////////

char out_buf[MAX_OUT], *out_p;

solver() : out_p(NULL) {}



void printf(const char* format, ...)
  __attribute__((format(printf, 2, 3)))
{
  if (!out_p) out_p = out_buf;

  va_list args;
  va_start(args, format);
  out_p += vsnprintf(out_p, sizeof(char) * (MAX_OUT - (out_p - out_buf)), format, args);
  va_end(args);

  if (out_p - out_buf >= MAX_OUT) {
    fprintf(stderr, "error: Output Limit Exceeded !!\n");
    exit(EXIT_FAILURE);
  }
}

void puts(const char *s) {
  printf("%s\n", s);
}

void debug(const char* format, ...)
  __attribute__((format(printf, 2, 3)))
{
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  fflush(stderr);
}



END_SOLVER /////////////////////////////////////////////////////////////////////////////////////////



double sec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}



void print_status(int c, int C, double t0, double t1, int nth) {
  static const int L = 5;
  if (C > L && c % (C / L) != 0) return;
  else if (c - (nth - 1) / 2 <= 0) fprintf(stderr, "[ case: %d / %d ]\n", c, C);
  else {
    double t = sec();
    fprintf(stderr, "[ case: %d / %d | time: %.3f / %.3f ]\n",
            c, C, t - t0, (t1 - t0) + (t - t1) / (c - (nth - 1) / 2) * C);
  }
}



int main(int argc, char **argv) {
  bool parallel = false, status = false;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0) parallel = status = true;
    else if (strcmp(argv[i], "-s") == 0) status = true;
    else {
      fprintf(stderr, "usage: %s [-p] [-s]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  double t0 = sec();
  init();
  double t1 = sec();
  if (status) fprintf(stderr, "[ init: %.3f ]\n", t1 - t0);

  string tmp;
  getline(cin, tmp);
  int C = atoi(tmp.c_str());

  if (!parallel) {
    if (status) fprintf(stderr, "[ mode: single thread ]\n");

    rep (c, C) {
      if (status) print_status(c, C, t0, t1, 1);

      solver *s = new solver();
      assert(s != NULL);
      s->input();
      s->solve();
      printf(OUTPUT_FORMAT, c + 1, s->out_buf);
      fflush(stdout);
      delete s;
    }
  }
  else {
#ifdef _OPENMP

    int nth = omp_get_max_threads();
    if (status) fprintf(stderr, "[ mode: parallel (%d) ]\n", nth);

    vector<string> out(C);
    vector<bool> done(C);
    int solve_c = 0, out_c = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

#pragma omp parallel for schedule(dynamic, 1)
    rep (c, C) {
      solver *s = new solver();
      assert(s != NULL);

      int my_c;
      omp_set_lock(&lock);
      {
        while (out_c < C && done[out_c]) {
          printf(OUTPUT_FORMAT, out_c + 1, out[out_c].c_str());
          fflush(stdout);
          out_c++;
        }
        if (status) print_status(solve_c, C, t0, t1, nth);
        my_c = solve_c++;
        s->input();
      }
      omp_unset_lock(&lock);

      s->solve();

      omp_set_lock(&lock);
      {
        out[my_c] = string(s->out_buf);
        done[my_c] = true;
      }
      omp_unset_lock(&lock);
      delete s;
    }

    omp_destroy_lock(&lock);

    while (out_c < C) {
      assert(done[out_c]);
      printf(OUTPUT_FORMAT, out_c + 1, out[out_c].c_str());
      out_c++;
    }

#else
    fprintf(stderr, "error: compile with -fopenmp !!\n");
#endif
  }

  exit(EXIT_SUCCESS);
}
