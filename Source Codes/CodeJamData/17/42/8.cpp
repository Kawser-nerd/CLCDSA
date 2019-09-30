#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, C, M;
    cin >> N >> C >> M;

    vector<int> DC(C, 0);
    vector<int> DP(N, 0);
    for (int i = 0; i < M; i++) {
      int pi, bi;
      cin >> pi >> bi;
      pi--; bi--;
      DC[bi]++;
      DP[pi]++;
    }

    int result = 0;
    for (int i = 0; i < C; i++) {
      result = max(result, DC[i]);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += DP[i];
      result = max(result, (cnt + i) / (i + 1));
    }

    int promos = 0;
    for (int i = 0; i < N; i++) {
      promos += max(0, DP[i] - result);
    }
    
    cout << "Case #" << t << ": ";
    cout << result << ' ' << promos << endl;
  }
  return 0;
}
