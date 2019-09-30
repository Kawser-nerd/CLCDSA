#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define rep(i, n)      for (int i=0; i<int(n); i++)
#define rep3(i, s, n)  for (int i=int(s); i<int(n); i++)
#define rev_rep(i, n)  for (int i=int(n)-1; i>=0; i-=1)

#define MAX_N 100010

int H, W, N;
typedef pair<int, int> P;
map<P, int> ctr;
long long ans[10];

int main() {
  cin >> H >> W >> N;
  for (int i=0; i<N; i++) {
    int a, b;
    cin >> a >> b;
    for (int xs=-1; xs<=1; xs++) {
      for (int ys=-1; ys<=1; ys++) {
        P p = P(b-1+xs, a-1+ys);
        if (p.first < 1    || p.second < 1 ||
            p.first >= W-1 || p.second >= H-1) {
          continue;
        }
        if (ctr.find(p) == ctr.end()) ctr[p] = 1;
        else ctr[p] += 1;
      }
    }
  }
  ans[0] = ((long)W-2)*((long)H-2);
  for (auto& kv : ctr) {
    ans[kv.second] += 1;
    ans[0] -= 1;
  }

  for (int i=0; i<10; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}