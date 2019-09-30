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
const char *OUTPUT_FORMAT = "%s"; //"Case #%d:\n%s";

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

int R, N, M, K;

int S;
vector<int> se[20000];
double se_score[20000];

map<ll, vector<int> > idx;

vector<int> cs;

double current_score = 0.0;

double score_table[20];

void gen(int i, int c, int r) {
  if (c == M + 1) {
    if (i == N) {
      int my_id = S++;
      se[my_id] = cs;
      se_score[my_id] = current_score;

      // rep (i, N) printf("%d", cs[i]); printf(" --- %f\n", current_score);
      // !fprintf(stderr, "score: %f\n", current_score);

      rep (b, 1 << N) {
        ll x = 1;
        rep (i, N) if (b & (1 << i)) x *= cs[i];
        vector<int> &v = idx[x];
        if (v.empty() || v.back() != my_id) idx[x].pb(my_id);
      }
    }
    return;
  }

  if (i < N) {
    cs[i] = c;
    gen(i + 1, c, r + 1);
  }

  {
    current_score += score_table[r];
    gen(i, c + 1, 0);
    current_score -= score_table[r];
  }
}

double factorial(int k) {
  double r = 1.0;
  for (int i = 1; i <= k; ++i) r *= i;
  return r;
}

void init() {
  int T_dummy;
  scanf("%d%d%d%d%d", &T_dummy, &R, &N, &M, &K);

  for (int k = 0; k <= N; ++k) {
    score_table[k] = log(pow(6, 12 - k)) - log(factorial(N - k)) - log(factorial(k));
    // fprintf(stderr, " %d:%f\n", k, score_table[k]);
  }

  cs.resize(N);
  S = 0;
  gen(0, 2, 0);

  puts("Case #1:");
  fprintf(stderr, "|S| = %d\n", S);
  // rep (s, S) { rep (i, N) printf("%d", se[s][i]); puts(""); }
}



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

ll X[110];

void input() {
  rep (k, K) cin >> X[k];
}

vector<int> intersection(const vector<int> &a, const vector<int> &b) {
  vector<int> res;

  int an = a.size(), bn = b.size();
  int ai = 0, bi = 0;
  while (ai < an && bi < bn) {
    /***/if (a[ai] < b[bi]) ++ai;
    else if (b[bi] < a[ai]) ++bi;
    else {
      assert(a[ai] == b[bi]);
      res.pb(a[ai]);
      ++ai;
      ++bi;
    }
  }
  return res;
}

void solve() {
  vector<int> ss;

  rep (k, K) {
    ll x = X[k];
    const vector<int> &tss = idx[x];
    // if (tss.size() > 1000000) continue;

    if (ss.empty()) ss = tss;
    else ss = intersection(ss, tss);
    // debug(" ss: %d\n", (int)ss.size());
  }

  if (ss.empty()) {
    debug("OMG!!\n");
    printf("%s\n", string(N, '2').c_str());
    return;
  }

  debug(" |ss| = %d\n", (int)ss.size());

  vector<int> ans_cs;
  double ans_score = -1E30;

  rep (i, ss.size()) {
    int s = ss[i];
    const vector<int> &cs = se[s];

    map<ll, int> xs;
    rep (b, 1 << N) {
      ll x = 1;
      rep (i, N) if (b & (1 << i)) x *= cs[i];
      ++xs[x];
    }

    double score = se_score[s];
    rep (k, K) {
      int n = xs[X[k]];
      if (n == 0) goto dmp;
      score += log(n);
    }

    // debug("score: %f\n", score);

    if (score > ans_score) {
      ans_cs = cs;
      ans_score = score;
    }
 dmp:;
  }

  rep (i, N) printf("%d", ans_cs[i]); puts("");
  return;
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
  static const int L = 100;
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

  // string tmp;
  // getline(cin, tmp);
  // int C = atoi(tmp.c_str());
  int C = R;

  if (!parallel) {
    if (status) fprintf(stderr, "[ mode: single thread ]\n");

    rep (c, C) {
      if (status) print_status(c, C, t0, t1, 1);

      solver *s = new solver();
      assert(s != NULL);
      s->input();
      s->solve();
      printf(OUTPUT_FORMAT, s->out_buf);
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
          printf(OUTPUT_FORMAT, out[out_c].c_str());
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
      printf(OUTPUT_FORMAT, out[out_c].c_str());
      out_c++;
    }

#else
    fprintf(stderr, "error: compile with -fopenmp !!\n");
#endif
  }

  exit(EXIT_SUCCESS);
}
