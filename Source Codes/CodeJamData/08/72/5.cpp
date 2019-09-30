#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

set <int> S;
int N;
const int M = 10007;
int data[1001];
int diffs[11];

void recurse(int offset, int dep) {
  diffs[dep] = (data[offset + (1<<dep)] - data[offset] + M) % M;
  int cur = offset + (2<<dep);
  bool checked = false;
  while (cur + (1<<dep) < N) {
    if (diffs[dep] != (data[cur + (1<<dep)] - data[cur] + M) % M)
      return;
    cur += 2<<dep;
    checked = true;
  }
  //cerr << "first: " << offset << " " << dep << endl;
  if (!checked) {
    for (int d = 0; d <= dep; d++)
      if (((N-offset)>>d)&1) {
	S.insert((data[N-(1<<d)] + diffs[d] + M) % M);
	return;
      }
    //cerr << dep << " " << offset << endl;
    S.insert(-1);
  }
  else {
    recurse(offset, dep+1);
    recurse(offset + (2<<dep), dep+1);
  }
}

int main(void) {

  int C;
  cin >> C;
  for (int c = 1; c <= C; c++) {
    S.clear();
    cin >> N;
    for (int i = 0; i < N; i++)
      cin >> data[i];
    recurse(0, 0);
    recurse(1, 0);
    int ans;
    /*
    for (set <int>::iterator it = S.begin(); it != S.end(); it++)
      cerr << *it << endl;
    */
    if (S.size() > 1) ans = -1;
    else ans = *S.begin();
    if (ans != -1)
      printf("Case #%d: %d\n", c, ans);
    else
      printf("Case #%d: UNKNOWN\n", c);
  }

}
