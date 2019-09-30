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
const char *OUTPUT_FORMAT = "Case #%d: \n%s"; //"Case #%d:\n%s";

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned long long ull;



void init() {}


BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////



int H, W;
char fld[110][110];
int id[110][110];
int problem;

void input() {
  scanf("%d%d", &H, &W);
  rep (y, H) scanf("%s", fld[y]);
}

set<ull> mem;
vector<vector<bool> > vis;

int search1(int y, int x) {
  if (fld[y][x] == '#') return 0;
  if (vis[y][x]) return 0;
  vis[y][x] = true;
  int res = 1;
  res += search1(y - 1, x);
  res += search1(y, x - 1);
  res += search1(y, x + 1);
  return res;
}

ull enc(vector<vector<bool> > &b) {
  ull e = 0;
  rep (y, H) rep (x, W) if (fld[y][x] != '#') e |= ull(b[y][x]) << id[y][x];
  return e;
}

void search2(vector<vector<bool> > &b) {
  ull e = enc(b);
  if (mem.count(e)) return;
  mem.insert(e);

  rep (y, H) rep (x, W) if (b[y][x] != (fld[y][x] == '0' + problem)) goto dmp;
  throw 0;
dmp:;

  const int dx[3] = {0, -1, 1};
  const int dy[3] = {1, 0, 0};
  rep (i, 3) {
    vector<vector<bool> > tb(H, vector<bool>(W));
    rep (y, H) rep (x, W) {
      if (b[y][x]) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (fld[ty][tx] == '#') { tx = x; ty = y; }
        // debug("%d %d\n", ty, tx);
        tb[ty][tx] = true;
      }
    }
    search2(tb);
  }
}

void solve() {

  int I = 0;
  rep (y, H) rep (x, W) if (fld[y][x] != '#') id[y][x] = I++;

  int reachable[20] = {};
  bool lucky[20] = {};

  rep (y, H) rep (x, W) {
    if (isdigit(fld[y][x])) {
      problem = fld[y][x] - '0';
      vis = vector<vector<bool> >(H, vector<bool>(W));
      reachable[problem] = search1(y, x);

      try {
        mem.clear();
        search2(vis);
        // printf("yeeeah %d\n", problem);
      } catch(...) {
        lucky[problem] = true;
      }
    }
  }

  rep (i, 20) if (reachable[i]) printf("%d: %d %s\n", i, reachable[i], lucky[i] ? "Lucky" : "Unlucky");
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
