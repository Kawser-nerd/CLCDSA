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
#include <unordered_map>

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



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////////////////////////

int N;
char C[10010];
vector<int> adj[10010];

void input() {
  scanf("%d", &N);
  rep (i, N) scanf(" %c", &C[i]);
  rep (i, N - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

map<pair<int, int>, string> mem_encode;

string encode(int v, int p) {
  auto i = mem_encode.insert(make_pair(make_pair(v, p), string()));
  if (!i.second) return i.first->second;
  
  string e = string("(") + C[v];
  vector<string> ce;
  for (int c : adj[v]) {
    if (c == p) continue;
    ce.push_back(encode(c, v));
  }
  sort(all(ce));
  for (string t : ce) e += t;
  e += ")";
  return i.first->second = e;
}

map<pair<int, int>, bool> mem_line;

bool line(int v, int p) {
  auto iter = mem_line.insert(make_pair(make_pair(v, p), false));
  if (!iter.second) return iter.first->second;
  
  unordered_map<string, vector<int>> ma;
  for (int c : adj[v]) {
    if (c == p) continue;
    ma[encode(c, v)].push_back(c);
  }

  int num_odd = 0;
  for (const auto &i : ma) if (i.second.size() % 2 == 1) ++num_odd;
  
  if (num_odd >= 2) {
    return iter.first->second = false;
  } else if (num_odd == 1) {
    for (const auto &i : ma) {
      if (i.second.size() % 2 == 1) { 
        return iter.first->second = line(i.second[0], v);
      }
    }
    assert(false);
  } else {
    assert(num_odd == 0);
    return iter.first->second = true;
  }
}

void solve() {
  // CASE 1: THERE EXISTS A ROOT
  rep (r, N) {
    if (line(r, -1)) {
      puts("SYMMETRIC");
      return;
    }
  }
  // CASE 2: THERE IS NO ROOT
  rep (u, N) {
    for (int v : adj[u]) {
      if (encode(u, v) == encode(v, u)) {
        puts("SYMMETRIC");
        return;        
      }
    }
  }
  puts("NOT SYMMETRIC");
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
