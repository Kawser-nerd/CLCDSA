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
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int cnt(const string &s) {
  rep (i, s.length()) {
    if (s[s.length() - i - 1] != '0') return i;
  }
  return s.length();
}

int main() {
  int cases;
  cin >> cases;
  rep (ca, cases) {
    int N;
    cin >> N;
    vector<string> A(N);
    rep (i, N) cin >> A[i];

    int ans = 0;
    rep (i, N) {
      int req = N - i - 1;
      // printf("i=%d, req=%d, cnt=%d\n", i, req, cnt(A[i]));
      if (cnt(A[i]) < req) {
        int j;
        for (j = i + 1; j < N; j++) {
          if (cnt(A[j]) >= req) break;
        }
        assert(j < N);
        // printf("i=%d, j=%d\n", i, j);
        while (j > i) {
          swap(A[j - 1], A[j]);
          ans++;
          j--;
        }
      }
    }

    printf("Case #%d: %d\n", ca + 1, ans);
  }

  return 0;
}
