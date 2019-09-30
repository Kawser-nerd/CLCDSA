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

const ll MOD = 1000000007;

inline ll mod(ll a, ll m) { return (a % m + m) % m; }

ll inverse(ll a, ll m) {
  if ((a = mod(a, m)) == 1) return 1;
  return mod((1 - m * inverse(m % a, a)) / a, m);
}

const int MAX = 110;
int phi[MAX + 1];

void init_phi() {
  for (int i = 0; i <= MAX; i++) phi[i] = i;
  for (int i = 2; i <= MAX; i++) {
    if (phi[i] != i) continue;
    for (int j = i; j <= MAX; j += i) phi[j] -= phi[j] / i;
  }
}

void init() {
  init_phi();
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

int H, W, fld[110][110];
ll c = 0;

bool check(int x, int y) {
  if (y < 0) return true;

  int cnt[4] = {};
  rep (d, 4) {
    int tx = (x + dx[d] + W) % W;
    int ty = y + dy[d];
    if (ty < 0 || H <= ty) continue;
    ++cnt[fld[ty][tx]];
  }
  return cnt[fld[y][x]] == fld[y][x];
}

void search(int x, int y) {
  if (x >= W) {
    search(0, y + 1);
  } else if (y >= H) {
    rep (tx, W) if (!check(tx, y - 1)) return;

    if (false) {
      rep (ty, H) {
        rep (tx, W) debug("%d ", fld[ty][tx]);
        debug("\n");
      }
      debug("--------- (%lld)\n", c);
    }

    c += 1;
  } else {
    for (fld[y][x] = 1; fld[y][x] <= 3; ++fld[y][x]) {
      if (!check(x, y - 1)) continue;
      search(x + 1, y);
    }
  }
}

ll doit(int h, int w) {
  H = h;
  W = w;
  c = 0;
  search(0, 0);
  return c;
}

ll doit_fast(int H, int W) {
  static constexpr int P[][3] = {
    {0, 2, 1},
    {1, 1, 1},
    {1, 2, 3},
    {1, 2, 6},
    {1, 3, 4},
  };
  static constexpr int N = sizeof(P) / sizeof(P[0]);

  ll dp[110][3] = {};
  dp[0][2] = 1;
  for (int h = 1; h <= H; ++h) {
    rep (i, N) {
      int pt = P[i][0];
      int ph = P[i][1];
      int pw = P[i][2];
      if (h < ph || W % pw != 0) continue;

      for (int t = 0; t <= 2; ++t) {
        if (t == pt) continue;
        (dp[h][pt] += dp[h - ph][t] * pw) %= MOD;
      }
    }
  }

  return (dp[H][0] + dp[H][1]) % MOD;
}

int H_, W_;

void input() {
  cin >> H_ >> W_;
}

void solve() {
  if (false) {
    const int MAX_W = 5;
    for (int h = 1; h <= 50; ++h) {
      for (int w = 1; w <= MAX_W; ++w) {
        debug("h=%d, w=%d: ans=%lld, out=%lld\n", h, w, doit(h, w), doit_fast(h, w));
        assert(doit(h, w) == doit_fast(h, w));
      }
    }
    exit(0);
  }

  ll ans = 0;
  for (int w = 1; w <= W_; ++w) {
    if (W_ % w != 0) continue;
    ll x = doit_fast(H_, w);
    (ans += x * phi[W_ / w]) %= MOD;
  }
  (ans *= inverse(W_, MOD)) %= MOD;
  printf("%lld\n", ans);
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
