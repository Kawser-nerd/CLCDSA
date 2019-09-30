#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using std::vector;
using std::string;

typedef int64_t ll;

int main() {
  int T;
  std::cin >> T;
  for (int tcase = 1; tcase <= T; ++tcase) {
    ll L, t, N, C;
    std::cin >> L >> t >> N >> C;

    vector<ll> d(N);

    for (int i = 0; i < C; ++i) {
      ll ai;
      std::cin >> ai;

      for (int k = 0; k * C + i < N; ++k) {
	d[k * C + i] = ai;
      }
    }

    ll elapsed = 0;
    
    int i;
    for (i = 0; i < N; ++i) {
      if (elapsed + 2 * d[i] > t) {
	break;
      }
      elapsed += 2 * d[i];
    }

    ll answer;
    if (i == N) {
      answer = elapsed;
    } else {
      ll parsecs = (t - elapsed) / 2;
      d[i] -= parsecs;
      elapsed = t;

      // now sort, reverse, add single for first L and double for rest.

      std::sort(d.begin() + i, d.end());
      std::reverse(d.begin() + i, d.end());
      int singled = 0;
      while (i < N) {
	if (singled < L) {
	  elapsed += d[i];
	  singled ++;
	} else {
	  elapsed += 2 * d[i];
	}
	++i;
      }

      answer = elapsed;
    }

    std::cout << "Case #" << tcase << ": " << answer << "\n";
  }
}

