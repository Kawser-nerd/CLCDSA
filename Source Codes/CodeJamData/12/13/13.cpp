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

const double EPS = 1E-7;


void init() {}



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

int N;
char D[60];
int S[60], P[60];

void input() {
  scanf("%d", &N);
  rep (i, N) scanf(" %c%d%d", &D[i], &S[i], &P[i]);
}

int G;
int adj[60][60];
int col[60];

void search(int v, int c) {
  if (col[v] != -1) {
    if (col[v] != c) throw 0;
    return;
  }
  col[v] = c;
  rep (w, G) if (adj[v][w]) search(w, 1 - c);
}

void check() {
  memset(col, -1, sizeof(col));
  rep (i, G) if (col[i] == -1) search(i, 0);
}

void join(int a, int b) {
  adj[a][b] = adj[b][a] = 2;
}

void split(int a, int b) {
  adj[a][b] = adj[b][a] = 1;
}

void process_free() {
  rep (i, N) {
    int b = 0;
    rep (j, N) b |= adj[i][j];
    if (0 == (b & 2)) rep (j, G) adj[i][j] = adj[j][i] = 0;
  }
}

void solve() {
  G = N + 2;
  memset(adj, 0, sizeof(adj));
  adj[N][N + 1] = adj[N + 1][N] = 1;
  rep (i, N) {
    int x = i;
    int y = D[i] == 'L' ? N : N + 1;
    adj[x][y] = adj[y][x] = 1;
  }
  rep (i, N) rep (j, i) {
    int a = i, b = j;
    if (P[a] > P[b]) swap(a, b);
    if (P[b] < P[a] + 5) join(a, b);
  }
  process_free();

  vector<pair<pair<double, int>, pair<int, int> > > evt;
  rep (i, N) rep (j, N) {
    double s1 = S[i], s2 = S[j];
    rep (k, 2) {
      double p1 = P[i] - (k == 0 ? 5 : 0);
      double p2 = P[j] - (k == 0 ? 0 : 5);
      if (s1 <= s2) continue;
      if (p1 > p2) continue;

      double t = (p2 - p1) / double(s1 - s2);
      assert(t >= -EPS);
      if (fabs(t) < EPS && k == 0) continue;
      evt.pb(mp(mp(t + (k == 0 ? -EPS : +EPS), k), k == 1 ? mp(i, j) : mp(j, i)));
    }
  }
  sort(all(evt));

  rep (i, evt.size()) {
    double T = evt[i].first.first;
    int a = evt[i].second.first;
    int b = evt[i].second.second;

    try {
      if (evt[i].first.second == 0) split(a, b);
      else join(a, b);

      process_free();
      check();
    } catch (...) {
      printf("%.10f\n", T);
      return;
    }
  }

  puts("Possible");
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
