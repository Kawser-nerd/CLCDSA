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

typedef tuple<int, ll, ll> tll;


typedef long long ll;
const ll MOD = 1000000007;

inline ll mod(ll a, ll m = MOD) { return (a % m + m) % m; }

ll inverse(ll a, ll m) {
  if ((a = mod(a, m)) == 1) return 1;
  return mod((1 - m * inverse(m % a, a)) / a, m);
}

const int MAX_F = 1000010;

ll fac[MAX_F + 1];

void init_fac() {
  fac[0] = 1;
  for (int k = 1; k <= MAX_F; ++k) {
    fac[k] = fac[k - 1] * k % MOD;
  }
}

ll choose(ll k, ll n) {
  return fac[n] * inverse(fac[k], MOD) % MOD * inverse(fac[n - k], MOD) % MOD;
}


void init() {
  init_fac();
}



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

int M, N;
string S[1010];

void input() {
  cin >> M >> N;
  rep (i, M) cin >> S[i];
}

void print(tll a) {
  printf("(%d, %lld, %lld)", get<0>(a), get<1>(a), get<2>(a));
}

tll search(int l, int r, int k) {
  // debug("%*s%d:[%d, %d)\n", k, "", k, l, r);
  if (r - l == 1 && k == (int)S[l].length()) return make_tuple(1, 1, 1);

  int cov = 0;
  ll cst = 0;

  vector<ll> dp(N + 1);  // dp[cov] := num of patterns
  if (k == (int)S[l].length()) {
    ++l;
    ++cov;
    dp[1] = 1;
  } else {
    dp[0] = 1;
  }

  int tl = l;
  for (int tr = l + 1; tr <= r; ++tr) {
    if (tr == r || S[tr - 1][k] != S[tr][k]) {
      tll x = search(tl, tr, k + 1);

      int n2 = get<0>(x);
      cov = min(cov + n2, N);
      cst += get<1>(x);
      ll p2 = get<2>(x);

      vector<ll> tmp(N + 1);
      for (int n1 = 0; n1 <= cov; ++n1) {
        ll p1 = dp[n1];
        if (p1 == 0) continue;

        for (int m = max(n1, n2); m <= min(N, n1 + n2); ++m) {
          int k = n1 + n2 - m;
          ll p3 = p1 * p2 % MOD
              * choose(k, m) % MOD
              * choose(n1 - k, m - k) % MOD;
          (tmp[m] += p3) %= MOD;
        }
      }
      dp.swap(tmp);

      tl = tr;
    }
  }

  return make_tuple(cov, cst + cov, dp[cov]);
}

void solve() {
  sort(S, S + M);
  tll a = search(0, M, 0);
  assert(get<0>(a) == N);
  printf("%lld %lld\n", get<1>(a), get<2>(a));
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
