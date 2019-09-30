//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <stdarg.h>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;


int _solved, _testNum;

class AbstractSolver {
  char* _ob;
  int _ob_pos;
  const int _buffer_size = 16 * (1<<20);
public:
  char* getob(){
    return _ob;
  }
  int _testId;
  AbstractSolver(int _testId) : _testId(_testId) {
      _ob = (char*)malloc(_buffer_size + 10);
      _ob_pos = 0;
      printf("Case #%d: ", _testId);
  }
  __attribute__((format(printf, 2, 3)))
  void printf (const char *format, ...) {
    va_list ap;
    va_start (ap, format);
    _ob_pos += vsnprintf (_ob + _ob_pos, _buffer_size - _ob_pos, format, ap);
    va_end (ap);
    assert(_ob_pos < _buffer_size - 10);
  }

  virtual void write(){
    _ob[_ob_pos] = 0;
    ::printf("%s", _ob);
  }

  virtual void solve() = 0;

  void run(){
    solve();
#pragma omp critical 
    {
      _solved++;
      if ((_solved - 1) * 100 / _testNum != _solved * 100 / _testNum || _solved <= 20 || _testNum - _solved <= 20) 
	TIMESTAMPf("%d%% of tests solved (%d/%d, %d more)", _solved * 100 / _testNum, _solved, _testNum, _testNum - _solved);
    }
  }
};


void PreCalc(){
}

class Solver : public AbstractSolver{
int r, c, k;
public:
Solver(int _testId) : AbstractSolver(_testId) {}


void read(){
  scanf("%d%d%d",&r,&c,&k);
}
int solve2(){
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, 1, 0, -1};
  if (k <= (r*c+1)/2) return 0;

  if (r % 2 == 1 && c % 2 == 1 && k == r*c/2 + 2 && r > 1 && c > 1) {
    return 3;
  }
  vector<vector<int>> v(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      for (int p = 0; p < 4; p++)
        if (0 <= i + dx[p] && i + dx[p] < r && 0 <= j + dy[p] && j + dy[p] < c) {
          v[i][j]++;
        }
  int ans = r * (c - 1) + c * (r - 1);
  vector<vector<int>> used(r, vector<int>(c, 1));
  for (int it = 0; it < r * c - k; it++){
    int bestx = -1;
    int besty = -1;
    int bestv = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        if (v[i][j] > bestv) {
          bestv = v[i][j];
          bestx = i;
          besty = j;
        }
    ans -= bestv;
    v[bestx][besty] = 0;
    used[bestx][besty] = 0;
    for (int p = 0; p < 4; p++)
      if (0 <= bestx + dx[p] && bestx + dx[p] < r && 0 <= besty + dy[p] && besty + dy[p] < c) {
        v[bestx+dx[p]][besty+dy[p]]--;
      }
  }
  /*for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d", used[i][j]);
    }
    printf("\n");
  }*/

  return ans;
}
void solve(){
  printf("%d\n", solve2());
  return;
  int n = r * c;
  int ans = 4 * r * c;
  int best = 0;
  int maskc = 0;
  for (int i = 0; i < r; i++)
    maskc |= 1<<(i * c);
  for (int i = 0; i < (1<<n); i++) {
    if (__builtin_popcount(i) != k) continue;
    int res = 0;
    res += __builtin_popcount(i & (i >> c));
    res += __builtin_popcount(i & ((i & ~maskc) >> 1));
    if (ans > res) {
      ans = res;
      best = i;
    }
  }
  int ans2 = solve2();
  printf("%d\n", ans);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d", !!(best & (1 << (i * c + j))));
    }
    printf("\n");
  }
  if (ans != ans2) {
    eprintf("FAIL: %d %d %d![ans1 = %d, ans2 = %d]\n%s\n", r, c, k, ans, ans2, getob());
    assert(ans == ans2);
  }
}

};

int main(){
  freopen(TASKNAME "-" TASKMOD".in","r",stdin);
  freopen(TASKNAME "-" TASKMOD".out","w",stdout);
	
  PreCalc();
  TIMESTAMP(PreCalc);	

  char buf[1000];
  fgets(buf, sizeof buf, stdin);
  sscanf(buf,"%d",&_testNum);

  vector<Solver*> solvers(_testNum);

  for (int i = 0; i < _testNum; i++) {
    solvers[i] = new Solver(i+1);
    solvers[i]->read();
  }
 
  #pragma omp parallel for 
  for (int i = 0; i < _testNum; i++) {
    solvers[i]->run();
  }

  for (int i = 0; i < _testNum; i++) {
    solvers[i]->write();
  }

  TIMESTAMP(end);
  return 0;
}
