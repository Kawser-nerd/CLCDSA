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



void init() {}


inline ll llabs(ll x) {
  return x < 0 ? -x : x;
}


BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

int N;
ll X[40];
ll F;

void input() {
  cin >> N;
  rep (i, N) cin >> X[i];
  cin >> F;
}


void solve() {
  sort(X, X + N);
  ll leftx = X[0];
  ll rightx = X[N - 1];
  N = remove(X, X + N, leftx) - X;
  N = remove(X, X + N, rightx) - X;
  N = remove(X, X + N, 0) - X;
  
  F -= (rightx - leftx) * 2;
  if (F < 0) {
    puts("NO SOLUTION");
    return;
  }

  // rep (i, N) printf("%lld ", X[i]); puts("");
  
  int L = N / 2, R = N - L;
  
  vector<ll> LS[20][2];
  vector<ll> RS[20][2];
  
  int bub = (int)round(pow(3.0, L));
  for (int b = 0; b < bub; ++b) {
    int t = b;
    
    int le = 0;
    ll d = 0;
    rep (i, L) {
      int k = t % 3;
      t /= 3;
      if (k == 1) {
        ++le;
        d -= X[i] * 2;
      }
      else if (k == 2) {
        if (le == 0) goto ng;
        --le;
        d += X[i] * 2;
      }
    }

    LS[le][0].pb(d);

    
    t = b;
    rep (i, L) {
      int k = t % 3;
      t /= 3;
      if (k == 0) LS[le][1].pb(d + 2 * llabs(X[i]));
    }
    
  ng:;
  }

  
  bub = (int)round(pow(3.0, R));
  for (int b = 0; b < bub; ++b) {
    int t = b;
    int ri = 0;
    ll d = 0;
    rep (i, R) {
      ll x = X[N - i - 1];
      int k = t % 3;
      t /= 3;
      
      if (k == 1) {
        if (ri == 0) goto ng2;
        --ri;
        d -= x * 2;
      }
      else if (k == 2) {
        ++ri;
        d += x * 2;
      }
    }

    RS[ri][0].pb(d);


    t = b;
    rep (i, R) {
      ll x = X[N - i - 1];
      int k = t % 3;
      t /= 3;

      if (k == 0) RS[ri][1].pb(d + 2 * llabs(x));
    }
  ng2:;
  }

  ll ans = 0;

  // puts("");
  
  for (int i = 0; i <= min(L, R); ++i) {
    for (int a = 0; a <= 1; ++a) {
      for (int b = 0; b <= 1; ++b) {
        if (a == 1 && b == 1) continue;
        
        vector<ll> &ls = LS[i][a];
        vector<ll> &rs = RS[i][b];

        sort(all(ls));
sort(all(rs));
    reverse(all(rs));

    /*
    printf("i=%d\n", i);
    // printf(" %d %d\n", ls.size(), rs.size());
    rep (i, ls.size()) printf(" %lld", ls[i]); puts("");
    rep (i, rs.size()) printf(" %lld", rs[i]); puts("");
    */

    int j = 0;
    rep (i, ls.size()) {
      while (j < (int)rs.size() && rs[j] + ls[i] > F) {
        ++j;
      }
      
      if (j < (int)rs.size()) {
        ans = max(ans, rs[j] + ls[i]);
      }
    }
      }
    }
  }

  printf("%lld\n", ans + (rightx - leftx) * 2);
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
