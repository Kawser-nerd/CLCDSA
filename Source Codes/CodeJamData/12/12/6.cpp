#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main(void) {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector <int> a(N), b(N);
    for (int i = 0; i < N; i++)
      cin >> a[i] >> b[i];
    vector <int> status(N);
    int score = 0, moves = 0;
    while (score < 2*N) {
      bool found = false;
      for (int i = 0; i < N; i++)
	if (b[i] <= score && status[i] < 2) {
	  score += 2-status[i]; moves++;
	  status[i] = 2;
	  found = true;
	  break;
	}
      if (found) continue;
      int best_i = -1, highest_b = -1;
      for (int i = 0; i < N; i++)
	if (a[i] <= score && status[i] == 0 && b[i] > highest_b) {
	  best_i = i;
	  highest_b = b[i];
	}
      if (best_i == -1) break;
      status[best_i] = 1;
      score++; moves++;
    }
    if (score == 2*N)
      printf("Case #%d: %d\n", t, moves);
    else
      printf("Case #%d: Too Bad\n", t);
  }
}
