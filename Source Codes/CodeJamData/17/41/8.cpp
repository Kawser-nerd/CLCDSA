#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 105

int N, P;
int memo[3][4][MAXN*MAXN*MAXN];

int solve(int r, vector<int>& freq) {
  int id = 0;
  for (int i = 1; i < freq.size(); i++) {
    id = id * MAXN + freq[i];
  }
  if (id == 0) {
    return 0;
  }

  int& ref = memo[P - 2][r][id];
  if (ref != -1) return ref;

  ref = 0;
  for (int i = 1; i < freq.size(); i++) {
    if (freq[i]) {
      freq[i]--;
      ref = max(ref, solve((r + i) % P, freq));
      freq[i]++;
    }
  }
  if (r == 0) {
    ref++;
  }
  return ref;
}

int main() {
  memset(memo, -1, sizeof(memo));

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N >> P;

    vector<int> freqs(P);
    for (int i = 0; i < N; i++) {
      int gi;
      cin >> gi;
      freqs[gi % P]++;
    }

    cout << "Case #" << t << ": " << freqs[0] + solve(0, freqs) << endl;
  }
  return 0;
}
